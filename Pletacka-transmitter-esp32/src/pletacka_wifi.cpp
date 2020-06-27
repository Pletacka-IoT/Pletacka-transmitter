#include "Pletacka_wifi.hpp"
#include "Pletacka.hpp"


Pletacka_wifi::Pletacka_wifi()
{
 
}

Pletacka_wifi::~Pletacka_wifi()
{
}

void Pletacka_wifi::init(pletackaConfig config)
{
    wifiCfg.wifiName = config.wifiName;
    wifiCfg.wifiPassword = config.wifiPassword;
    wifiCfg.wifiChanel = config.wifiChenel;
    wifiCfg.wifiDefaulAp = config.wifiDefaulAp;
    wifiCfg.apName = config.apName;
    wifiCfg.apPassword = config.apPassword;

    configConnection();
}

void Pletacka_wifi::configConnection()
{
    if(wifiCfg.wifiDefaulAp)
    {
        startAP();
    }
    else
    {
        connectWifi();
    }
    
}


void Pletacka_wifi::connectWifi()
{
    pletacka.println("Connecting to " + wifiCfg.wifiName);
    WiFi.begin(wifiCfg.wifiName.c_str(), wifiCfg.wifiPassword.c_str());
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        pletacka.print(".");
    }

    pletacka.println("\nWiFi connected");
    pletacka.println("IP address: ");
    pletacka.println(String(WiFi.localIP()));
}

void Pletacka_wifi::startAP()
{
    pletacka.println("Starting **" + wifiCfg.apName + "** AP");
    WiFi.softAP(wifiCfg.apName.c_str(), wifiCfg.apPassword.c_str(), wifiCfg.apChanel );
}