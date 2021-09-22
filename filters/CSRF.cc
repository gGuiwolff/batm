/**
 *
 *  CSRF.cc
 *
 */

#include "CSRF.h"

using namespace drogon;

void CSRF::doFilter(const HttpRequestPtr &req,
                         FilterCallback &&fcb,
                         FilterChainCallback &&fccb)
{
    auto ff = req->getHeader("content-type");
    LOG_DEBUG <<ff;
    //Edit your logic here
	if (1)
    {
        //Passed
        fccb();
        return;
    }
    //Check failed
    auto res = drogon::HttpResponse::newHttpResponse();
    res->setStatusCode(k500InternalServerError);
    fcb(res);
}
