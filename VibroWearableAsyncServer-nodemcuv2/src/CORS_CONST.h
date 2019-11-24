/**
	Cross-Origin Resource Sharing (CORS) is a mechanism that uses additional 
	HTTP headers to tell browsers to give a web application running at one origin,
	access to selected resources from a different origin. 
	A web application executes a cross-origin HTTP request when it requests a resource 
	that has a different origin (domain, protocol, or port) from its own.
	More you can find on https://developer.mozilla.org/en-US/docs/Web/HTTP/CORS
	
	@author Dariusz Rumiński
*/

#ifndef CORS_CONST_h
#define CORS_CONST_h

const char* TEXT_PLAIN = "text/plain";

const char* ACCESS_CONTROL_ALLOW_ORIGIN = "Access-Control-Allow-Origin";
const char* ASTERIX = "*";
const char* ACCESS_CONTROL_ALLOW_METHODS = "Access-Control-Allow-Methods";
const char* METHODS = "POST,GET,OPTIONS";
const char* ACCESS_CONTROL_ALLOW_HEADERS = "Access-Control-Allow-Headers";
const char* HEADERS = "Origin, X-Requested-With, Content-Type, Accept";
const char* OK_ = "OK";
const char* INFO_FOR_D = "Hi Dariusz, I'm working!!!";
const char* PARAM_PIN = "p";
const char* PARAM_VOLTAGE = "v";


#endif
