/**
 *
 *  CSRF.h
 *
 */

#pragma once

#include <drogon/HttpFilter.h>
using namespace drogon;


class CSRF : public HttpFilter<CSRF>
{
  public:
    CSRF() {}
    virtual void doFilter(const HttpRequestPtr &req,
                          FilterCallback &&fcb,
                          FilterChainCallback &&fccb) override;
};

