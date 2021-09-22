#include "demo_v1_User.h"
#include <drogon/HttpResponse.h>

using namespace drogon::orm;
using namespace demo::v1;

//add definition of your processing function here
void Users::post(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback)
{ 
     LOG_DEBUG <<"ola";
     std::string n = "novonome";
     auto db = app().getDbClient();
     //auto res = db->execSqlSync("INSERT INTO cppteste(nome) VALUES ("+n+")");
     auto res = db->execSqlSync("INSERT INTO cppteste(nome) VALUES ('novonome')");
}
