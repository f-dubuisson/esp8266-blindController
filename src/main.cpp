#include <ESP8266WebServer.h>
#include "wifi.h"
#include "Blind.h"
#include "config.h"


ESP8266WebServer server(httpPort);
Blind blind(upPin, downPin);

static const String COMMAND_NONE  = "none";
static const String COMMAND_STOP  = "stop";
static const String COMMAND_UP    = "up";
static const String COMMAND_DOWN  = "down";
String command = COMMAND_NONE;
long commandStartTime = 0;
int duration = 0;

void handleRoot() {
  if ((server.args() < 2) || (server.arg("c").length() == 0) ||(server.arg("t").length() == 0)) {
    Serial.println("Invalid request; expected: c=<command>&t=<duration>");
    return;
  }

  command = server.arg("c");
  duration = server.arg("t").toInt();
  commandStartTime = millis();

  if (command == COMMAND_STOP) {
    blind.stop();
    command = COMMAND_NONE;
  } else if (command == COMMAND_DOWN) {
    blind.down();
  } else if (command == COMMAND_UP) {
    blind.up();
  } else {
    Serial.println("Invalid command: " + command);
    String message = "Command Not Found\n\n";
    server.send(404, "text/plain", message);
    command = COMMAND_NONE;
    return ;
  }

  String result = "Command to execute: " + command + " for " + duration + "s";
  server.send(200, "text/plain", result);
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  server.send(404, "text/plain", message);
}

void setup() {
  Serial.begin(9600);

  setupWifi(ssid, password);

  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}

/** Fonction loop() **/
void loop() {
  server.handleClient();

  if ((command != COMMAND_NONE) && (commandStartTime + duration < millis())) {
    blind.stop();
    command = COMMAND_NONE;
  }
  delay(100);
}
