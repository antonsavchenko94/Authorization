#include "interactive_certificate_verifier.hpp"


void interactiveCertificateVerifier::verify(vmime::shared_ptr<vmime::security::cert::certificateChain> chain, const vmime::string &hostname){
  try{
    setX509TrustedCerts(m_trustedCerts);

    defaultCertificateVerifier::verify(chain, hostname);
  }
  catch (vmime::exceptions::certificate_verification_exception&){
    // Obtain subject's certificate
    vmime::shared_ptr <vmime::security::cert::certificate> cert = chain->getAt(0);
    //std::cout << "Server sent a '" << cert->getType() << "'" << " certificate." << std::endl;

    if (cert->getType() == "X.509"){
      m_trustedCerts.push_back(vmime::dynamicCast <vmime::security::cert::X509Certificate>(cert));
      setX509TrustedCerts(m_trustedCerts);
      defaultCertificateVerifier::verify(chain, hostname);
    }
    return;
  }
}

std::vector <vmime::shared_ptr <vmime::security::cert::X509Certificate> >
    interactiveCertificateVerifier::m_trustedCerts;

