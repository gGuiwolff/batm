#include <drogon/drogon.h>
#include <drogon/HttpResponse.h>
#include <stack>
#include <iostream>
#include <fstream>

using namespace drogon;
using namespace std;
using namespace drogon::orm;

//struct Item{ string nome; };

int main() {
    

    //Set HTTP listener address and port
    app().addListener("0.0.0.0",8000);
    //Load config file
    app().loadConfigFile("../config.json");
    //Run HTTP framework,the method will block in the internal event loop
    app().registerHandler("/",
                          [](const HttpRequestPtr &req,
                             std::function<void(const HttpResponsePtr &)> &&callback) {
                              //auto resp = HttpResponse::newHttpResponse();
			      //if (req->method()==Get)
			      //{
			      /*auto resp = HttpResponse::newHttpResponse();
			      //auto &origin = req->getHeader("Origin");
			      resp->addHeader("Access-Control-Allow-Origin", "*");
			      resp->addHeader("Access-Control-Allow-Methods", "GET");
			      resp->addHeader("Access-Control-Allow-Headers",
					      "x-requested-with,content-type, Accept, Authorization");
			      //resp->addHeader("Access-Control-Allow-Credentials","true");
			      //callback(resp);
			      //req.append(resp);
			      //resp->addHeader("Access-Control-Allow-Origin", "*");
			      
			      //resp->addHeader("Access-Control-Allow-Origin", "*");*/
			      

                              //THIS CONNECTION WORKING FINE
                              //note that we shouldn't use a sync interface of a FastDbClient;
                              
			      auto db = app().getDbClient();
			      auto res = db->execSqlSync("SELECT id,nome FROM cppteste");
			      Json::Value ret;
			      ret["data"] = "teste";
			      auto resp2=HttpResponse::newHttpJsonResponse(ret);

                              //resp2->addHeader("Access-Control-Allow-Origin", "*");
			      
			      /*if (res.affectedRows())
                                  resp->setBody(res[0]["nome"].as<string>()); 
                              else
                                  resp->setBody("Nothing ");*/
			      
                              callback(resp2);
			      //}
                          }, {Get, " "});
			  
			
    app().run();
    return 0;
}
