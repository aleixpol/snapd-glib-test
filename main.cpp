#include <QCoreApplication>
#include <Snapd/Client>

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    QSnapdClient client;
    auto request = client.connect();
    request->runSync();
    Q_ASSERT(request->error() == QSnapdRequest::NoError);

    auto req = client.list();
    QObject::connect(req, &QSnapdRequest::complete, &app, &QCoreApplication::quit);
    req->runAsync();

    return app.exec();
}
