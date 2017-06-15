// 
// 
// 

#include "gate.h"


gate::gate(bool mode, int Id, int sensor)
{
	gate_func = mode;
	gate_id = Id;
	pinMode(Id, OUTPUT);
}
gate::~gate()
{
	return;
}

void gate::release(int card_id)
{
	String payload;
	status = GATE_RELEASED;
	digitalWrite(gate_id, HIGH);
	while (digitalRead(gate_sensor));
	if (gate_func = ENTREE_GATE) payload = String(card_id) + ",3";
	else payload = String(card_id) + ",4";
	gate::postentry(payload);
	gate::block();
	return;
}

void gate::block(void)
{
	status = GATE_BLOCKED;
	digitalWrite(gate_id, LOW);
	return;
}

bool gate::getStatus(void)
{
	return status;
}


void gate::postentry(String payload)
{
	HTTPClient http;
	http.begin("http://192.168.137.1:8081/server/back-end/php/enterRU.php");
	int code_returned = http.POST(payload);
	return;
}
