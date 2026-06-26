#include <WiFi.h>
#include <WebServer.h>
#include <WebSocketsServer.h>

//----------------------------------------------------------------------------------
// Defines
//----------------------------------------------------------------------------------

#ifndef SSID
    #define SSID "YOUR_SSID"
#endif
#ifndef PASSWORD
    #define PASSWORD "YOUR_PASSWORD"
#endif
#ifndef READ_MS
    #define READ_MS 20
#endif

WebServer server(80);
WebSocketsServer webSocket(81);

//----------------------------------------------------------------------------------
// HTML Page
//----------------------------------------------------------------------------------

const char HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>EMG</title>
        <script src="https://cdn.plot.ly/plotly-2.26.0.min.js"></script>
        <style>
            html, body {
                margin: 0;
                padding: 0;
                height: 100vh;
                width: 100vw;
                overflow: hidden;
                font-family: sans-serif;
            }

            body {
                display: flex;
                flex-direction: column;
            }

            main {
                flex-grow: 1;
                display: flex;
                flex-direction: column;
                padding: 10px 20px;
                box-sizing: border-box;
                gap: 10px;
            }

            .banner-container {
                display: flex;
                justify-content: center;
                align-items: center;
                height: 140px;
                flex-shrink: 0;
            }

            .banner-container img {
                max-height: 120px;
                object-fit: contain;
            }

            .plot-div {
                flex: 1;
                min-height: 0;
            }

        </style>
    </head>
    <body>
        <div class="banner-container">
            <img src="https://raw.githubusercontent.com/pontarolo/2026.1_DEC0013_EMG-INTEGRATED-WITH-AN-ESP32-WEB-SERVER/main/images/banner_3.png" height="120">
        </div>
        <main>
            <div id="channel-one-div" class="plot-div"></div>
            <div id="channel-two-div" class="plot-div"></div>
        </main>
        <script>
            const channel_one = document.getElementById('channel-one-div');
            const channel_two = document.getElementById('channel-two-div');
            const points = 300;
    
            Plotly.newPlot(channel_one, [{y: [], mode: 'lines', line: {color: '#880808', width: 4}}], 
            {margin: {t: 40, b: 40, l: 50, r: 20},
            xaxis: {showgrid: false, zeroline: false, showticklabels: false},
            yaxis: {range: [0, 3.3], gridcolor: '#333', title: 'Voltage'}}, 
            {responsive: true, displayModeBar: false });

            Plotly.newPlot(channel_two, [{y: [], mode: 'lines', line: {color: '#880808', width: 4}}], 
            {margin: {t: 40, b: 40, l: 50, r: 20},
            xaxis: {showgrid: false, zeroline: false, showticklabels: false},
            yaxis: {range: [0, 3.3], gridcolor: '#333', title: 'Voltage'}}, 
            {responsive: true, displayModeBar: false });

            const webSocket = new WebSocket('ws://' + location.hostname + ':81/');
            webSocket.binaryType = "arraybuffer";

            webSocket.onmessage = (e) => {
            if (e.data instanceof ArrayBuffer) {
                const view = new DataView(e.data);
                const ch_one_reading = view.getUint16(0, true) / 1000.0;
                const ch_two_reading = view.getUint16(2, true) / 1000.0;
                Plotly.extendTraces(channel_one, { y: [[ch_one_reading]] }, [0], points);
                Plotly.extendTraces(channel_two, { y: [[ch_two_reading]] }, [0], points);
            }};
</script>
</body></html>
)=====";

//----------------------------------------------------------------------------------
// Setup
//----------------------------------------------------------------------------------

void setup() {
    Serial.begin(115200);
    analogReadResolution(12);
    
    WiFi.setSleep(false);
    WiFi.begin(SSID, PASSWORD);
    
    while (WiFi.status() != WL_CONNECTED);
    
    Serial.println(WiFi.localIP());

    server.on("/", []() {
        server.send_P(200, "text/html", HTML);
    });

    server.begin();
    webSocket.begin();
}

//----------------------------------------------------------------------------------
// Main Loop
//----------------------------------------------------------------------------------

void loop() {
    server.handleClient();
    webSocket.loop();

    unsigned long last_time = 0;

    if (millis() - last_time >= READ_MS) {
        uint16_t emg_data[2] = {(uint16_t)analogReadMilliVolts(35), (uint16_t)analogReadMilliVolts(34)};
        webSocket.broadcastBIN((uint8_t*)emg_data, sizeof(emg_data));
        last_time = millis();
    }
}