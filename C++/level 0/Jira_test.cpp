// Jira_test.cpp
#include <iostream>
#include <curl/curl.h>

int main() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.atlassian.com/admin/v1/orgs/39ca848k-7540-193c-j759-5kac825b0j08/events");
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L); // Указываем, что это GET запрос

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Authorization: Bearer ATCTT3xFfGN05c4fhwNA9Y6VbIA5LMg897u6cHaXKy2xCdHq_ZfaIajr_arVcT0-blxBMu2dwVx-g6baZBrp1Pse6mFCyOLtG0a2Go2WzT28Kq6twnBe3NMUBnDtCjCP_MymL8JcPvOGWH6rG0iJUBSIFJaRFzYnVQTrUbj_UrYskIzXNFaTW3c=C69C91C5");
        headers = curl_slist_append(headers, "Accept: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Опция для вывода ответа сервера
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](void *contents, size_t size, size_t nmemb, void *userp) -> size_t {
            ((std::string*)userp)->append((char*)contents, size * nmemb);
            return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Выполнение запроса
        res = curl_easy_perform(curl);

        // Проверка на ошибки
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        std::cout << readBuffer << std::endl; // Вывод ответа

        // Освобождение ресурсов
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers); // Очистка списка заголовков
    }
    return 0;
}
 