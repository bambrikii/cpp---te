#include <iostream>
#include <CkRest.h>

int main(int argc, char const *argv[])
{
    /* code */

    {
        // This example requires the Chilkat API to have been previously unlocked.
        // See Global Unlock Sample for sample code.

        CkRest rest;

        // Connect to the REST server.
        bool bTls = true;
        int port = 443;
        bool bAutoReconnect = true;
        bool success = rest.Connect("www.alphavantage.co", port, bTls, bAutoReconnect);
        if (success != true)
        {
            std::cout << rest.lastErrorText() << "\r\n";
            return;
        }

        // Get a stock quote:
        // Sending GET request to https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=MSFT&apikey=my_api_key
        success = rest.AddQueryParam("function", "TIME_SERIES_DAILY");
        success = rest.AddQueryParam("symbol", "AAPL");
        success = rest.AddQueryParam("apikey", "my_api_key");
        const char *responseJson = rest.fullRequestNoBody("GET", "/query");
        if (rest.get_LastMethodSuccess() != true)
        {
            std::cout << rest.lastErrorText() << "\r\n";
            return;
        }

        std::cout << responseJson << "\r\n";
    }
    return 0;
}
