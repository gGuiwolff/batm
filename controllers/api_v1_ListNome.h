#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
namespace api
{
namespace v1
{
class ListNome:public drogon::HttpController<ListNome>
{
  public:
    METHOD_LIST_BEGIN
    //use METHOD_ADD to add your custom processing function here;

    METHOD_ADD(ListNome::getNome,"/list",Get,Post,Options,"CSRF");//path is /api/v1/ListNome/{arg2}/{arg1}
    //METHOD_ADD(ListNome::your_method_name,"/{1}/{2}/list",Get);//path is /api/v1/ListNome/{arg1}/{arg2}/list
    //ADD_METHOD_TO(ListNome::your_method_name,"/absolute/path/{1}/{2}/list",Get);//path is /absolute/path/{arg1}/{arg2}/list

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    void getNome(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback) const;
    // void your_method_name(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,double p1,int p2) const;
};
}
}
