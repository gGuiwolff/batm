#include "api_v1_ListNome.h"
using namespace api::v1;
using namespace drogon::orm;

void ListNome::getNome(const HttpRequestPtr &req,
             std::function<void (const HttpResponsePtr &)> &&callback) const
{
    LOG_DEBUG <<" get his information";
    //std::string n = "novonome";
    auto db = app().getDbClient();
    std::string n = "meunome5";
    //auto res = db->execSqlSync("INSERT INTO cppteste(nome) VALUES ('novonome')");
    //auto res = db->execSqlSync("INSERT INTO cppteste(nome) VALUES($1)",n);
    
    //Verify the validity of the token, etc.
    //Read the database or cache to get user information
    auto res = db->execSqlSync("SELECT id,nome FROM cppteste");
    Json::Value ret;
    ret["topics"] = Json::arrayValue;
    for(auto &r : res)
    {
      Json::Value topic;
      std::string answers;
      topic["id"] = r["id"].as<std::string>();
      topic["nome"] = r["nome"].as<std::string>();
      ret["topics"].append(topic);
    }
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    resp->addHeader("Access-Control-Allow-Origin", "*");
    resp->addHeader("Access-Control-Allow-Methods", "GET,POST,OPTIONS");
    resp->addHeader("Access-Control-Allow-Headers",
		                                  "x-requested-with,content-type, Accept, Authorization");
    resp->addHeader("Access-Control-Allow-Credentials","true");
    callback(resp);
}
