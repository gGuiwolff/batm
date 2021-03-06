#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
namespace demo
{
namespace v1
{
class Users:public drogon::HttpController<Users>
{
  public:
    METHOD_LIST_BEGIN
    //use METHOD_ADD to add your custom processing function here;
    METHOD_ADD(Users::post,"/colocar",Post);//path is /demo/v1/User/{arg2}/{arg1}
    //METHOD_ADD(User::your_method_name,"/{1}/{2}/list",Get);//path is /demo/v1/User/{arg1}/{arg2}/list
    //ADD_METHOD_TO(User::your_method_name,"/absolute/path/{1}/{2}/list",Get);//path is /absolute/path/{arg1}/{arg2}/list

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    void post(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback);
    // void your_method_name(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,double p1,int p2) const;
};
}
}
