#include <stdio.h>
#include <curl/curl.h>
#define _CRT_SECURE_NO_WARNINGS

// write to stdout
void write_callback(void *data, size_t size, size_t nmemb, void *ptr)
{
    fwrite(data, size, nmemb, stdout);
}

int main(void)
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        /* Get a file listing from sunet */
        curl_easy_setopt(curl, CURLOPT_URL, "ftp://192.168.1.79/");
        curl_easy_setopt(curl, CURLOPT_USERNAME, "toybrick");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "toybrick");
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "NLST");
        curl_easy_setopt(curl, CURLOPT_NOPROXY, "*");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    return 0;
}