#include <QtCore/QCoreApplication>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <locale>
#include <clocale>
#include "vmime/base.hpp"


#include "vmime/vmime.hpp"
#include "vmime/platforms/posix/posixHandler.hpp"
#if VMIME_HAVE_TLS_SUPPORT

// Certificate verifier (TLS/SSL)
class interactiveCertificateVerifier : public vmime::security::cert::defaultCertificateVerifier
{
public:

    void verify(vmime::shared_ptr <vmime::security::cert::certificateChain> chain, const vmime::string& hostname);

private:

    static std::vector <vmime::shared_ptr <vmime::security::cert::X509Certificate> > m_trustedCerts;
};
#endif // VMIME_HAVE_TLS_SUPPORT

