#include "api_v1_PostNome.h"
using namespace api::v1;
using namespace drogon::orm;

void PostNome::postNomes(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,std::string &&nome) 
{
	  LOG_DEBUG <<req->getCookie("gggg");
  //LOG_DEBUG <<nome;
  auto db = app().getDbClient();
  //auto res = db->execSqlSync("INSERT INTO cppteste(nome) VALUES ('olaolaola')");
  auto res = db->execSqlSync("INSERT INTO cppteste(nome) VALUES($1)",nome);
  Json::Value ret;
  ret["nome"] = nome;
  auto resp = HttpResponse::newHttpJsonResponse(ret);
  resp->addHeader("Access-Control-Allow-Origin", "*");
  resp->addHeader("Access-Control-Allow-Methods", "GET,POST,OPTIONS");
   resp->addHeader("Access-Control-Allow-Headers",                      
		   "x-requested-with,content-type, Accept, Authorization");
   resp->addHeader("Access-Control-Allow-Credentials","true");
  callback(resp);
}
