#include <WiFi.h>
#include <WebServer.h>
#include <WebSocketsServer.h>

#define SSID ""
#define PASSWORD ""

WebServer server(80);
WebSocketsServer webSocket(81);
unsigned long last_time = 0;

const char HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>EMG</title>
        <script src="https://cdn.plot.ly/plotly-2.26.0.min.js"></script>
        <style>
            body {
                margin: 0;
            }
        </style>
    </head>
    <body>
        <div id="plot"></div>
        <script>
            const plotDiv = document.getElementById('plot');
            const points = 300;
    
            Plotly.newPlot(plotDiv, [{y: [], mode: 'lines', line: {color: '#00e676', width: 3}}], 
            {paper_bgcolor: '#121212', plot_bgcolor: '#121212', margin: {t: 40, b: 40, l: 50, r: 20},
            xaxis: {showgrid: false, zeroline: false, showticklabels: false},
            yaxis: {range: [0, 3.3], gridcolor: '#333', title: 'Voltagem'}}, 
            {responsive: true, displayModeBar: false });

            const webSocket = new WebSocket('ws://' + location.hostname + ':81/');
            webSocket.binaryType = "arraybuffer";

            ws.onmessage = (e) => {
            if (e.data instanceof ArrayBuffer) {
                const view = new DataView(e.data);
                const voltage = (view.getUint16(0, true)  * 3.3) / 4095.0;
                Plotly.extendTraces(plotDiv, { y: [[voltage]] }, [0], points);
            }};
</script>
</body></html>
)=====";

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

void loop() {
  server.handleClient();
  webSocket.loop();

  if (millis() - last_time >= 20) {
      uint16_t raw_value = analogRead(35); 
      webSocket.broadcastBIN((uint8_t*)&raw_value, sizeof(raw_value));
    last_time = millis();
  }
}