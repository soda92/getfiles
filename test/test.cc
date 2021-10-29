#include <string>
#include <vector>
#include <fstream>
#include <fmt/core.h>
#include <curl/curl.h>

#include <filesystem>
namespace fs = std::filesystem;
#include <boost/algorithm/string.hpp>

namespace str = boost::algorithm;
size_t writefunc(void *ptr, size_t size, size_t nmemb, std::string *s)
{
    s->append(static_cast<char *>(ptr), size * nmemb);
    return size * nmemb;
}

void write_callback(void *data, size_t size, size_t nmemb, void *ptr)
{
    fwrite(data, size, nmemb, stdout);
}

int main(int argc, char **argv)
{
    CURL *handle;
    /* global initialization */
    int rc = curl_global_init(CURL_GLOBAL_ALL);
    if (rc)
        return rc;

    /* initialization of easy handle */
    handle = curl_easy_init();
    if (!handle)
    {
        curl_global_cleanup();
        return CURLE_OUT_OF_MEMORY;
    }

    auto path = fs::path(argv[0]);
    path = path.parent_path();
    path /= "config.txt";
    std::ifstream file(path);
    std::vector<std::string> data;
    std::string line;
    while (std::getline(file, line))
    {
        data.push_back(line);
    }
    auto path_str = data[0];
    std::vector<std::string> v;
    str::split(v, path_str, [](auto c)
               { return c == '='; });
    path_str = v.at(1);
    fmt::print("{}\n", path_str);
    data.erase(data.begin());
    for (auto line : data)
    {
        str::split(v, line, str::is_space());
        // for (auto i : v)
        // {
        //     fmt::print("{}\n", i);
        // }
        auto addr = v[1];
        auto dirname = v[0];
        auto path = fs::path(path_str);
        path /= dirname;
        if (!fs::is_directory(path))
        {
            fs::create_directories(path);
        }
        auto ftp_addr = fmt::format("ftp://{}/lamp_sample/", addr);

        curl_easy_reset(handle);
        curl_easy_setopt(handle, CURLOPT_URL, ftp_addr.c_str());
        auto username = v[2];
        curl_easy_setopt(handle, CURLOPT_USERNAME, username.c_str());
        auto passwd = v[3];
        curl_easy_setopt(handle, CURLOPT_PASSWORD, passwd.c_str());
        // curl_easy_setopt(handle, CURLOPT_CUSTOMREQUEST, "NLST");
        curl_easy_setopt(handle, CURLOPT_DIRLISTONLY, 1L);
        // curl_easy_setopt(handle, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(handle, CURLOPT_NOPROXY, "*");
        std::string s;
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, &s);
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_callback);

        curl_easy_perform(handle);
        str::split(v, s, [](auto c)
                   { return c == '\n'; });
        for (auto i : v)
        {
            std::string trimed = str::trim_copy(i);
            if (trimed != "")
            {
                fmt::print("{}\n", trimed);
            }
        }
    }
    curl_easy_cleanup(handle);
    return 0;
}
