#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
namespace api
{
namespace v1
{
class PostNome:public drogon::HttpController<PostNome>
{
  public:
    METHOD_LIST_BEGIN
    //use METHOD_ADD to add your custom processing function here;
    METHOD_ADD(PostNome::postNomes,"/postnomes?nome={1}",Get,Post,Options);//path is /api/v1/PostNome/{arg2}/{arg1}
    //METHOD_ADD(PostNome::your_method_name,"/{1}/{2}/list",Get);//path is /api/v1/PostNome/{arg1}/{arg2}/list
    //ADD_METHOD_TO(PostNome::your_method_name,"/absolute/path/{1}/{2}/list",Get);//path is /absolute/path/{arg1}/{arg2}/list

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    void postNomes(const HttpRequestPtr& req,
		   std::function<void (const HttpResponsePtr &)> &&callback,
		   std::string &&nome);
    // void your_method_name(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,double p1,int p2) const;
};
}
}
