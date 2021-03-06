#ifndef DATABASE_H
#define DATABASE_H

#include <./class/authserver.h>
#include <QObject>
#include <QString>
#include <QtSql>

class DataBase : public QObject {
    Q_OBJECT

private:
    DataBase(const DataBase&);

public:
    DataBase();
    static DataBase& getDatabase() {
        static DataBase database;
        return database;
    }

    ~DataBase();
    void createAccount(QString login, QString password);
    bool accountExist(const QString& login)
        const;  // pretty sure this isn't mutating anything
    void createFriendListTable(QString name);
    void insertIntoFriendListTable(QString targetTable, QString value);
    bool checkIfValueIsInTable(QString table, QString value);
    QString getPassword(QString login);
    QString getRecords(QString table);
    void removeRecord(QString table, QString value);
    QString getUsersStartingAt(QString table, QString name);
    QString getNonFriends(QString token, QString part);

private:
    void execute(QString cmd);
    QSqlDatabase db;
signals:

public slots:
};

#endif  // DATABASE_H
