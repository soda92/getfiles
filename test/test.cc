#include <curl/curl.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <fmt/core.h>
#include <filesystem>
namespace fs = std::filesystem;
#include <source_location>
#include <boost/algorithm/string.hpp>
namespace str = boost::algorithm;

constexpr std::string get_location()
{
    return std::string(std::source_location::current().file_name());
}

int main()
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

    fs::path path = fs::path(get_location());
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
        auto addr = v[1];
        auto dirname = v[0];
        auto path = fs::path(path_str);
        path /= dirname;
        if (!fs::is_directory(path))
        {
            fs::create_directories(path);
        }
        // auto ftp_addr = fmt::format("ftp://{}/lamp_sample/", addr);

        // curl_easy_reset(handle);
        // curl_easy_setopt(handle, CURLOPT_URL, ftp_addr);
        // auto username = v[2];
        // curl_easy_setopt(handle, CURLOPT_USERNAME, username);
        // curl_easy_setopt(handle, CURLOPT_PASSWORD, "toybrick");
        

        fmt::print("{}\n", line);
    }
    return 0;
}