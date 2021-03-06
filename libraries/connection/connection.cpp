
#include "connection.h"
/* This is the constructor of the connection class
 * It constructs a WiFiServer object into the selected port
*/	
connection::connection(int set_port) :
	WiFiServer(set_port)
{
	port = set_port;
	return;
}


/* This is the destructor of the connection class
* It does not do anything by now
*/
connection::~connection()
{
	return;
}

/* This is the start server method
* It starts a server with localhost IP and the 
* port passed for the constructor
*/
void connection::startServer()
{
	WiFiServer::begin();
}

/* This is the check for client method
* It fills the client with the app connection
* and returns 1 when a client is connected
* That means that someone is trying to get into RU
*/
int connection::checkForClient()
{
	app = WiFiServer::available();
	if (!app) {
		return 0;
	}
	if (!app.available()) {
		return 1;
	}
}

/* This is the request from client method
* It fills a response string with the message
* sent from the client (app)
*/

String connection::requestFromClient()
{
	String request = app.readStringUntil('\t');
	app_card = (request.substring(0, 8)).toInt();
	app.flush();
	return request.substring(8);
}

/* This is the write to client method
* It sends a message back for the client
* It is used by the app to know if the access
* was denied or not
*/
void connection::write2Client(String value)
{
	app.print(value);
}

/* This is the get status method
* It checks the connection status
*/
bool connection::getStatus()
{
	return WiFiServer::status();
}

void connection::post2server(String payload)
{
	HTTPClient http;
	http.begin("http://192.168.137.1:8081/server/back-end/php/enterRU.php");
	int code_returned = http.POST(payload);
}

String connection::getFromServer(void)
{
	HTTPClient http;
	http.begin("http://192.168.137.1:8081/server/back-end/php/enterRU.php");
	int httpCode = http.GET();
	String payload = http.getString();
	return payload;
}


int connection::getTime(void)
{
	HTTPClient http;
	http.begin("http://192.168.137.1:8081/server/back-end/php/returnTime.php");
	int httpCode = http.GET();
	String payload = http.getString();
	return payload.toInt();
}