#include "mainwindow.h"
#include "email_address_retrieval_application.h"

int main(int argc, char *argv[]) {
    EmailAddressRetrievalApplication eara;
    return eara.exec(argc, argv);
}
