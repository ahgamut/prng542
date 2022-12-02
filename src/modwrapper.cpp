#include "prng_dummy.h"
#include "prng_midsq.h"
#include "prng_lehmer.h"
#include "prng_lcg.h"
#include "prng_blum2shub.h"
#include "prng_xorshift.h"

RCPP_MODULE(prng_internals) {
    using namespace Rcpp;

    class_<PRNGDummy>("_PRNGDummy")
        .constructor<u64, u64>()
        .method("unif", &PRNGDummy::unif)
        .method("draw", &PRNGDummy::draw)
        .const_method("toString", &PRNGDummy::toString);

    class_<PRNGMidsq>("_PRNGMidsq")
        .constructor<u64, u64>()
        .method("unif", &PRNGMidsq::unif)
        .method("draw", &PRNGMidsq::draw)
        .const_method("toString", &PRNGMidsq::toString);
    
    class_<PRNGLehmer>("_PRNGLehmer")
        .constructor<u64, u64, u64>()
        .method("unif", &PRNGLehmer::unif)
        .method("draw", &PRNGLehmer::draw)
        .const_method("toString", &PRNGLehmer::toString);

    class_<PRNGLCG>("_PRNGLCG")
        .constructor<u64, u64, u64, u64>()
        .method("unif", &PRNGLCG::unif)
        .method("draw", &PRNGLCG::draw)
        .const_method("toString", &PRNGLCG::toString);

    class_<PRNGBlum2Shub>("_PRNGBlum2Shub")
        .constructor<u64, u64, u64>()
        .method("unif", &PRNGBlum2Shub::unif)
        .method("draw", &PRNGBlum2Shub::draw)
        .const_method("toString", &PRNGBlum2Shub::toString);

    class_<PRNGXorshift>("_PRNGXorshift")
        .constructor<u64, u64, u64>()
        .method("unif", &PRNGXorshift::unif)
        .method("draw", &PRNGXorshift::draw)
        .const_method("toString", &PRNGXorshift::toString);
}
