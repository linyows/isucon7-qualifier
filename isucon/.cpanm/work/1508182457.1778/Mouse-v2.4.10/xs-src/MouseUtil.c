/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.34 from the
 * contents of MouseUtil.xs. Do not edit this file, edit MouseUtil.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs-src/MouseUtil.xs"
#include "mouse.h"
#include "xs_version.h"

#define MY_CXT_KEY "Mouse::Util::_guts" XS_VERSION
typedef struct {
    HV* metas;
} my_cxt_t;
START_MY_CXT

#define ISA_CACHE "::LINEALIZED_ISA_CACHE::"

#ifdef no_mro_get_linear_isa
AV*
mouse_mro_get_linear_isa(pTHX_ HV* const stash){
    GV* const cachegv = *(GV**)hv_fetchs(stash, ISA_CACHE, TRUE);
    AV* isa;
    SV* gen;
    CV* get_linear_isa;

    if(!isGV(cachegv))
        gv_init(cachegv, stash, ISA_CACHE, sizeof(ISA_CACHE)-1, TRUE);

    isa = GvAVn(cachegv);
    gen = GvSVn(cachegv);


    if(SvIOK(gen) && SvIVX(gen) == (IV)mro_get_pkg_gen(stash)){
        return isa; /* returns the cache if available */
    }
    else{
        SvREFCNT_dec(isa);
        GvAV(cachegv) = isa = newAV();
    }

    get_linear_isa = get_cv("Mouse::Util::get_linear_isa", TRUE);

    {
        SV* avref;
        dSP;

        ENTER;
        SAVETMPS;

        PUSHMARK(SP);
        mXPUSHp(HvNAME_get(stash), HvNAMELEN_get(stash));
        PUTBACK;

        call_sv((SV*)get_linear_isa, G_SCALAR);

        SPAGAIN;
        avref = POPs;
        PUTBACK;

        if(IsArrayRef(avref)){
            AV* const av  = (AV*)SvRV(avref);
            I32 const len = AvFILLp(av) + 1;
            I32 i;

            for(i = 0; i < len; i++){
                HV* const stash = gv_stashsv(AvARRAY(av)[i], FALSE);
                if(stash)
                    av_push(isa, newSVpv(HvNAME(stash), 0));
            }
            SvREADONLY_on(isa);
        }
        else{
            Perl_croak(aTHX_ "Mouse:Util::get_linear_isa() didn't return an ARRAY reference");
        }

        FREETMPS;
        LEAVE;
    }

    sv_setiv(gen, (IV)mro_get_pkg_gen(stash));
    return isa;
}
#endif /* !no_mor_get_linear_isa */

#ifdef DEBUGGING
SV*
mouse_av_at_safe(pTHX_ AV* const av, I32 const ix){
    assert(av);
    assert(SvTYPE(av) == SVt_PVAV);
    assert(AvMAX(av) >= ix);
    return AvARRAY(av)[ix] ? AvARRAY(av)[ix] : &PL_sv_undef;
}
#endif

void
mouse_throw_error(SV* const metaobject, SV* const data /* not used */, const char* const fmt, ...){
    dTHX;
    va_list args;
    SV* message;

    assert(metaobject);
    assert(fmt);

    va_start(args, fmt);
    message = vnewSVpvf(fmt, &args);
    va_end(args);

    {
        dSP;
        PUSHMARK(SP);
        EXTEND(SP, 6);

        PUSHs(metaobject);
        mPUSHs(message);

        if(data){ /* extra arg, might be useful for debugging */
            mPUSHs(newSVpvs("data"));
            PUSHs(data);
            mPUSHs(newSVpvs("depth"));
            mPUSHi(-1);
        }
        PUTBACK;
        if(SvOK(metaobject)) {
            call_method("throw_error", G_VOID);
        }
        else {
            call_pv("Mouse::Util::throw_error", G_VOID);
        }
        croak("throw_error() did not throw the error (%"SVf")", message);
    }
}

#if (PERL_BCDVERSION < 0x5014000)
/* workaround Perl-RT #69939 */
I32
mouse_call_sv_safe(pTHX_ SV* const sv, I32 const flags) {
    I32 count;
    ENTER;
    /* Don't do SAVETMPS */

    SAVEGENERICSV(ERRSV); /* local $@ */
    ERRSV = newSV(0);

    count = Perl_call_sv(aTHX_ sv, flags | G_EVAL);

    if(sv_true(ERRSV)){
        SV* const err = sv_mortalcopy(ERRSV);
        LEAVE;
        sv_setsv(ERRSV, err);
        croak(NULL); /* rethrow */
    }

    LEAVE;

    return count;
}
#endif

void
mouse_must_defined(pTHX_ SV* const value, const char* const name) {
    assert(value);
    assert(name);

    SvGETMAGIC(value);
    if(!SvOK(value)){
        croak("You must define %s", name);
    }
}

void
mouse_must_ref(pTHX_ SV* const value, const char* const name, svtype const t) {
    assert(value);
    assert(name);

    SvGETMAGIC(value);
    if(!(SvROK(value) && (t == SVt_NULL || SvTYPE(SvRV(value)) == t))) {
        croak("You must pass %s, not %s",
            name, SvOK(value) ? SvPV_nolen(value) : "undef");
    }
}


bool
mouse_is_class_loaded(pTHX_ SV * const klass){
    HV *stash;
    GV** gvp;
    HE* he;

    if (!(SvPOKp(klass) && SvCUR(klass))) { /* XXX: SvPOK does not work with magical scalars */
        return FALSE;
    }

    stash = gv_stashsv(klass, FALSE);
    if (!stash) {
        return FALSE;
    }

    if (( gvp = (GV**)hv_fetchs(stash, "VERSION", FALSE) )) {
        if(isGV(*gvp) && GvSV(*gvp) && SvOK(GvSV(*gvp))){
            return TRUE;
        }
    }

    if (( gvp = (GV**)hv_fetchs(stash, "ISA", FALSE) )) {
        if(isGV(*gvp) && GvAV(*gvp) && av_len(GvAV(*gvp)) != -1){
            return TRUE;
        }
    }

    hv_iterinit(stash);
    while(( he = hv_iternext(stash) )){
        GV* const gv = (GV*)HeVAL(he);

        if(isGV(gv)){
            if(GvCVu(gv)){ /* is GV and has CV */
                hv_iterinit(stash); /* reset */
                return TRUE;
            }
        }
        else if(SvOK(gv)){ /* is a stub or constant */
            hv_iterinit(stash); /* reset */
            return TRUE;
        }
    }
    return FALSE;
}


SV*
mouse_call0 (pTHX_ SV* const self, SV* const method) {
    dSP;
    SV *ret;

    PUSHMARK(SP);
    XPUSHs(self);
    PUTBACK;

    call_sv_safe(method, G_SCALAR | G_METHOD);

    SPAGAIN;
    ret = POPs;
    PUTBACK;

    return ret;
}

SV*
mouse_call1 (pTHX_ SV* const self, SV* const method, SV* const arg1) {
    dSP;
    SV *ret;

    PUSHMARK(SP);
    EXTEND(SP, 2);
    PUSHs(self);
    PUSHs(arg1);
    PUTBACK;

    call_sv_safe(method, G_SCALAR | G_METHOD);

    SPAGAIN;
    ret = POPs;
    PUTBACK;

    return ret;
}

int
mouse_predicate_call(pTHX_ SV* const self, SV* const method) {
    return sv_true( mcall0(self, method) );
}

SV*
mouse_get_metaclass(pTHX_ SV* metaclass_name){
    dMY_CXT;
    HE* he;

    assert(metaclass_name);
    assert(MY_CXT.metas);

    if(IsObject(metaclass_name)){
        HV* const stash = SvSTASH(SvRV(metaclass_name));

        metaclass_name = newSVpvn_share(HvNAME_get(stash), HvNAMELEN_get(stash), 0U);
        sv_2mortal(metaclass_name);
    }

    he = hv_fetch_ent(MY_CXT.metas, metaclass_name, FALSE, 0U);

    return he ? HeVAL(he) : &PL_sv_undef;
}

MAGIC*
mouse_mg_find(pTHX_ SV* const sv, const MGVTBL* const vtbl, I32 const flags){
    MAGIC* mg;

    assert(sv != NULL);
    for(mg = SvMAGIC(sv); mg; mg = mg->mg_moremagic){
        if(mg->mg_virtual == vtbl){
            return mg;
        }
    }

    if(flags & MOUSEf_DIE_ON_FAIL){
        croak("mouse_mg_find: no MAGIC found for %"SVf, sv_2mortal(newRV_inc(sv)));
    }
    return NULL;
}

GV*
mouse_stash_fetch(pTHX_ HV* const stash, const char* const name, I32 const namelen, I32 const create) {
    GV** const gvp = (GV**)hv_fetch(stash, name, namelen, create);

    if(gvp){
        if(!isGV(*gvp)){
            gv_init(*gvp, stash, name, namelen, GV_ADDMULTI);
        }
        return *gvp;
    }
    else{
        return NULL;
    }
}

void
mouse_install_sub(pTHX_ GV* const gv, SV* const code_ref) {
    CV* cv;

    assert(gv != NULL);
    assert(code_ref != NULL);
    assert(isGV(gv));
    assert(IsCodeRef(code_ref));

    if(GvCVu(gv)){ /* delete *slot{gv} to work around "redefine" warning */
        SvREFCNT_dec(GvCV(gv));
        GvCV_set(gv, NULL);
    }

    sv_setsv_mg((SV*)gv, code_ref); /* *gv = $code_ref */

    /* name the CODE ref if it's anonymous */
    cv = (CV*)SvRV(code_ref);
    if(CvANON(cv)
        && CvGV(cv) /* a cv under construction has no gv */ ){
        HV* dbsub;

        /* update %DB::sub to make NYTProf happy */
        if((PL_perldb & (PERLDBf_SUBLINE|PERLDB_NAMEANON))
            && PL_DBsub && (dbsub = GvHV(PL_DBsub))
        ){
            /* see Perl_newATTRSUB() in op.c */
            SV* const subname = sv_newmortal();
            HE* orig;

            gv_efullname3(subname, CvGV(cv), NULL);
            orig = hv_fetch_ent(dbsub, subname, FALSE, 0U);
            if(orig){
                gv_efullname3(subname, gv, NULL);
                (void)hv_store_ent(dbsub, subname, HeVAL(orig), 0U);
                SvREFCNT_inc_simple_void_NN(HeVAL(orig));
            }
        }

        CvGV_set(cv, gv);
        CvANON_off(cv);
    }
}

#line 372 "xs-src/MouseUtil.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
	    Perl_croak_nocontext("Usage: %s::%s(%s)", hvname, gvname, params);
        else
	    Perl_croak_nocontext("Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
	Perl_croak_nocontext("Usage: CODE(0x%" UVxf ")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#define croak_xs_usage        S_croak_xs_usage

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#if PERL_VERSION_LE(5, 21, 5)
#  define newXS_deffile(a,b) Perl_newXS(aTHX_ a,b,file)
#else
#  define newXS_deffile(a,b) Perl_newXS_deffile(aTHX_ a,b)
#endif

#line 516 "xs-src/MouseUtil.c"

XS_EUPXS(XS_Mouse__Util___register_metaclass_storage); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Mouse__Util___register_metaclass_storage)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "metas, cloning");
    {
	HV*	metas;
	bool	cloning = (bool)SvTRUE(ST(1))
;

	STMT_START {
		SV* const xsub_tmp_sv = ST(0);
		SvGETMAGIC(xsub_tmp_sv);
		if (SvROK(xsub_tmp_sv) && SvTYPE(SvRV(xsub_tmp_sv)) == SVt_PVHV){
		    metas = (HV*)SvRV(xsub_tmp_sv);
		}
		else{
		    Perl_croak_nocontext("%s: %s is not a HASH reference",
				"Mouse::Util::__register_metaclass_storage",
				"metas");
		}
	} STMT_END
;
#line 376 "xs-src/MouseUtil.xs"
{
    if(cloning){
        MY_CXT_CLONE;
        MY_CXT.metas = NULL;
    }
    {
        dMY_CXT;
        if(MY_CXT.metas && ckWARN(WARN_REDEFINE)){
            Perl_warner(aTHX_ packWARN(WARN_REDEFINE), "Metaclass storage more than once");
        }
        MY_CXT.metas = metas;
        SvREFCNT_inc_simple_void_NN(metas);
    }
}
#line 557 "xs-src/MouseUtil.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Mouse__Util_is_valid_class_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Mouse__Util_is_valid_class_name)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "sv");
    {
	bool	RETVAL;
	SV*	sv = ST(0)
;
#line 394 "xs-src/MouseUtil.xs"
{
    SvGETMAGIC(sv);
    if(SvPOKp(sv) && SvCUR(sv) > 0){
        UV i;
        RETVAL = TRUE;
        for(i = 0; i < SvCUR(sv); i++){
            char const c = SvPVX(sv)[i];
            if(!(isALNUM(c) || c == ':')){
                RETVAL = FALSE;
                break;
            }
        }
    }
    else{
        RETVAL = SvNIOKp(sv) ? TRUE : FALSE;
    }
}
#line 591 "xs-src/MouseUtil.c"
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Mouse__Util_is_class_loaded); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Mouse__Util_is_class_loaded)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "sv");
    {
	bool	RETVAL;
	SV*	sv = ST(0)
;

	RETVAL = is_class_loaded(sv);
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Mouse__Util_get_code_info); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Mouse__Util_get_code_info)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "code");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 420 "xs-src/MouseUtil.xs"
    GV* gv;
    HV* stash;
#line 628 "xs-src/MouseUtil.c"
	CV*	code;

	STMT_START {
                HV *st;
                GV *gvp;
		SV * const xsub_tmp_sv = ST(0);
		SvGETMAGIC(xsub_tmp_sv);
                code = sv_2cv(xsub_tmp_sv, &st, &gvp, 0);
		if (!code) {
		    Perl_croak_nocontext("%s: %s is not a CODE reference",
				"Mouse::Util::get_code_info",
				"code");
		}
	} STMT_END
;
#line 423 "xs-src/MouseUtil.xs"
    if((gv = CvGV(code)) && isGV(gv) && (stash = GvSTASH(gv))){
        EXTEND(SP, 2);
        mPUSHs(newSVpvn_share(HvNAME_get(stash), HvNAMELEN_get(stash), 0U));
        mPUSHs(newSVpvn_share(GvNAME_get(gv), GvNAMELEN_get(gv), 0U));
    }
#line 650 "xs-src/MouseUtil.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Mouse__Util_get_code_package); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Mouse__Util_get_code_package)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "code");
    {
#line 432 "xs-src/MouseUtil.xs"
    HV* stash;
#line 666 "xs-src/MouseUtil.c"
	SV *	RETVAL;
	CV*	code;

	STMT_START {
                HV *st;
                GV *gvp;
		SV * const xsub_tmp_sv = ST(0);
		SvGETMAGIC(xsub_tmp_sv);
                code = sv_2cv(xsub_tmp_sv, &st, &gvp, 0);
		if (!code) {
		    Perl_croak_nocontext("%s: %s is not a CODE reference",
				"Mouse::Util::get_code_package",
				"code");
		}
	} STMT_END
;
#line 434 "xs-src/MouseUtil.xs"
    if(CvGV(code) && isGV(CvGV(code)) && (stash = GvSTASH(CvGV(code)))){
        RETVAL = newSVpvn_share(HvNAME_get(stash), HvNAMELEN_get(stash), 0U);
    }
    else{
        RETVAL = &PL_sv_no;
    }
#line 690 "xs-src/MouseUtil.c"
	RETVAL = sv_2mortal(RETVAL);
	ST(0) = RETVAL;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Mouse__Util_get_code_ref); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Mouse__Util_get_code_ref)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "package, name");
    {
	CV *	RETVAL;
	SV*	package = ST(0)
;
	SV*	name = ST(1)
;
#line 446 "xs-src/MouseUtil.xs"
{
    HV* stash;
    STRLEN name_len;
    const char* name_pv;
    GV* gv;

    must_defined(package, "a package name");
    must_defined(name,    "a subroutine name");

    stash = gv_stashsv(package, FALSE);
    if(!stash){
        XSRETURN_UNDEF;
    }

    name_pv = SvPV_const(name, name_len);
    gv = stash_fetch(stash, name_pv, name_len, FALSE);
    RETVAL = gv ? GvCVu(gv) : NULL;

    if(!RETVAL){
        XSRETURN_UNDEF;
    }
}
#line 733 "xs-src/MouseUtil.c"
	{
	    SV * RETVALSV;
	    RETVALSV = newRV((SV*)RETVAL);
	    RETVALSV = sv_2mortal(RETVALSV);
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Mouse__Util_generate_isa_predicate_for); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Mouse__Util_generate_isa_predicate_for)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items < 1 || items > 2)
       croak_xs_usage(cv,  "arg, predicate_name= NULL");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV*	arg = ST(0)
;
	SV*	predicate_name;

	if (items < 2)
	    predicate_name = NULL;
	else {
	    predicate_name = ST(1)
;
	}
#line 477 "xs-src/MouseUtil.xs"
{
    const char* name_pv = NULL;
    CV* xsub;

    must_defined(arg, ix == 0 ? "a class_name" : "method names");

    if(predicate_name){
        must_defined(predicate_name, "a predicate name");
        name_pv = SvPV_nolen_const(predicate_name);
    }

    if(ix == 0){
        xsub = mouse_generate_isa_predicate_for(aTHX_ arg, name_pv);
    }
    else{
        xsub = mouse_generate_can_predicate_for(aTHX_ arg, name_pv);
    }

    if(predicate_name == NULL){ /* anonymous predicate */
        mXPUSHs( newRV_inc((SV*)xsub) );
    }
}
#line 788 "xs-src/MouseUtil.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Mouse__Util_install_subroutines); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Mouse__Util_install_subroutines)
{
    dVAR; dXSARGS;
    if (items < 1)
       croak_xs_usage(cv,  "into, ...");
    {
	SV*	into = ST(0)
;
#line 504 "xs-src/MouseUtil.xs"
{
    HV* stash;
    I32 i;

    must_defined(into, "a package name");
    stash = gv_stashsv(into, TRUE);

    if( ((items-1) % 2) != 0 ){
        croak_xs_usage(cv, "into, name => coderef [, other_name, other_coderef ...]");
    }

    for(i = 1; i < items; i += 2) {
        SV* const name = ST(i);
        SV* const code = ST(i+1);
        STRLEN len;
        const char* pv;
        GV* gv;

        must_defined(name, "a subroutine name");
        must_ref(code, "a CODE reference", SVt_PVCV);

        pv = SvPV_const(name, len);
        gv = stash_fetch(stash, pv, len, TRUE);

        mouse_install_sub(aTHX_ gv, code);
    }
}
#line 832 "xs-src/MouseUtil.c"
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Mouse__Util); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Mouse__Util)
{
#if PERL_VERSION_LE(5, 21, 5)
    dVAR; dXSARGS;
#else
    dVAR; dXSBOOTARGSAPIVERCHK;
#endif
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(file);

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#if PERL_VERSION_LE(5, 21, 5) && defined(XS_APIVERSION_BOOTCHECK)
  XS_APIVERSION_BOOTCHECK;
#endif

        newXS_deffile("Mouse::Util::__register_metaclass_storage", XS_Mouse__Util___register_metaclass_storage);
        newXS_deffile("Mouse::Util::is_valid_class_name", XS_Mouse__Util_is_valid_class_name);
        newXS_deffile("Mouse::Util::is_class_loaded", XS_Mouse__Util_is_class_loaded);
        newXS_deffile("Mouse::Util::get_code_info", XS_Mouse__Util_get_code_info);
        newXS_deffile("Mouse::Util::get_code_package", XS_Mouse__Util_get_code_package);
        newXS_deffile("Mouse::Util::get_code_ref", XS_Mouse__Util_get_code_ref);
        cv = newXS_deffile("Mouse::Util::generate_can_predicate_for", XS_Mouse__Util_generate_isa_predicate_for);
        XSANY.any_i32 = 1;
        cv = newXS_deffile("Mouse::Util::generate_isa_predicate_for", XS_Mouse__Util_generate_isa_predicate_for);
        XSANY.any_i32 = 0;
        newXS_deffile("Mouse::Util::install_subroutines", XS_Mouse__Util_install_subroutines);

    /* Initialisation Section */

#line 368 "xs-src/MouseUtil.xs"
{
    MY_CXT_INIT;
    MY_CXT.metas = NULL;
}

#line 882 "xs-src/MouseUtil.c"

    /* End of Initialisation Section */

#if PERL_VERSION_LE(5, 21, 5)
#  if PERL_VERSION_GE(5, 9, 0)
    if (PL_unitcheckav)
        call_list(PL_scopestack_ix, PL_unitcheckav);
#  endif
    XSRETURN_YES;
#else
    Perl_xs_boot_epilog(aTHX_ ax);
#endif
}

