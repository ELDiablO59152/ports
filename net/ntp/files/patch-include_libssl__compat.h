--- include/libssl_compat.h.orig	2017-03-21 13:04:20 UTC
+++ include/libssl_compat.h
@@ -37,7 +37,7 @@
 #endif
 
 /* ----------------------------------------------------------------- */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 /* ----------------------------------------------------------------- */
 
 # include <openssl/objects.h>
@@ -107,10 +107,13 @@ extern int	sslshim_X509_get_signature_ni
 
 #define OpenSSL_version_num	SSLeay
 #define OpenSSL_version		SSLeay_version
+
+#if !defined(LIBRESSL_VERSION_NUMBER) || LIBRESSL_VERSION_NUMBER < 0x20800000L
 #define X509_get0_notBefore	X509_get_notBefore
 #define X509_getm_notBefore	X509_get_notBefore
 #define X509_get0_notAfter	X509_get_notAfter
 #define X509_getm_notAfter	X509_get_notAfter
+#endif
 
 /* ----------------------------------------------------------------- */
 #endif /* OPENSSL_VERSION_NUMBER < v1.1.0 */
