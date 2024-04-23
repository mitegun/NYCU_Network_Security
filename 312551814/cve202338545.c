#include <curl/curl.h>

int main(int argc, char *argv[])
{
  CURLcode ret;
  CURL *hnd;

  // Initialize a curl handle
  hnd = curl_easy_init();
  
  // Set various options for the curl handle
  curl_easy_setopt(hnd, CURLOPT_BUFFERSIZE, 32768);
  curl_easy_setopt(hnd, CURLOPT_URL, "http://127.0.0.1:8000/");
  curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
  curl_easy_setopt(hnd, CURLOPT_PROXY, "socks5h://127.0.0.1:10801/");
  curl_easy_setopt(hnd, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
  curl_easy_setopt(hnd, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_2TLS);
  curl_easy_setopt(hnd, CURLOPT_VERBOSE, 1L);
  curl_easy_setopt(hnd, CURLOPT_FTP_SKIP_PASV_IP, 1L);
  curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);
  
  // Perform the HTTP request
  ret = curl_easy_perform(hnd);
  
  // Cleanup the curl handle
  curl_easy_cleanup(hnd);
  hnd = NULL;

  // Return the result of the curl operation
  return (int)ret;
}

