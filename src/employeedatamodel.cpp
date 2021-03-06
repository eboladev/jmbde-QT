/*
 * EmployeeDataModel.cpp
 * jmbde
 *
 *  Copyright (c) 2013, 2014 Jürgen Mülbert. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the European Union Public Licence (EUPL),
 * version 1.1.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * European Union Public Licence for more details.
 *
 * You should have received a copy of the European Union Public Licence
 * along with this program. If not, see
 * http://www.osor.eu/eupl/european-union-public-licence-eupl-v.1.1
 *
 */


#include "employeedatamodel.h"


EmployeeDataModel::EmployeeDataModel(QObject *parent) : DataModell(parent)
{

}

EmployeeDataModel::~EmployeeDataModel() {
}

void EmployeeDataModel::addDataSet() {

   QDate today = QDate::currentDate();
   QString todayDateString = today.toString(Qt::ISODate);

   QSqlQuery query;
   query.prepare(QLatin1String("INSERT INTO EMPLOYEE ("
                              ":employee_id, :title_id, "
                               ":firstname, :lastname, "
                               ":address_id, :gender, "
                               ":birthday, :email, "
                               ":datacare, :active, "
                               ":startdate, :enddate, "
                               ":department_id, :function_id, "
                               ":computer_id, :printer_id, "
                               ":phone_id, :mobile_id, "
                               ":fax_id, "
                               ":employee_account_id, :employee_document_id, "
                               ":lastupdate)"));

    query.bindValue(QLatin1String(":employee_nr"), Database::Table::DEFAULT_FOREIGN_VALUE);
    query.bindValue(QLatin1String(":title_id"), Database::Table::DEFAULT_FOREIGN_VALUE);
    query.bindValue(QLatin1String(":firstname"),QLatin1String("Test"));
    query.bindValue(QLatin1String(":lastname"), QLatin1String("Test"));
    query.bindValue(QLatin1String(":address_id"), Database::Table::DEFAULT_FOREIGN_VALUE);
    query.bindValue(QLatin1String(":gender"), QLatin1String("m"));
    query.bindValue(QLatin1String(":birthday"), todayDateString);
    query.bindValue(QLatin1String("email"), QLatin1String(" "));
    query.bindValue(QLatin1String(":datacare"), 0);
    query.bindValue(QLatin1String(":active"), 1);
    query.bindValue(QLatin1String(":startdate"), todayDateString);
    query.bindValue(QLatin1String(":enddate"), todayDateString);
    query.bindValue(QLatin1String(":department_id"), Database::Table::DEFAULT_FOREIGN_VALUE);
    query.bindValue(QLatin1String(":function_id"), Database::Table::DEFAULT_FOREIGN_VALUE);
    query.bindValue(QLatin1String(":computer_id"), Database::Table::DEFAULT_FOREIGN_VALUE);
    query.bindValue(QLatin1String(":printer_id"), Database::Table::DEFAULT_FOREIGN_VALUE);
    query.bindValue(QLatin1String(":phone_id"), Database::Table::DEFAULT_FOREIGN_VALUE);
    query.bindValue(QLatin1String(":mobile_id"), Database::Table::DEFAULT_FOREIGN_VALUE);
    query.bindValue(QLatin1String(":fax_id"), Database::Table::DEFAULT_FOREIGN_VALUE);
    query.bindValue(QLatin1String(":employee_account_id"), Database::Table::DEFAULT_FOREIGN_VALUE);
    query.bindValue(QLatin1String(":employee_document_id"), Database::Table::DEFAULT_FOREIGN_VALUE);
    query.bindValue(QLatin1String(":last_update"), todayDateString);

   bool retValue = query.exec();
   if (retValue == false) {
       qDebug() << db.lastError();
   } else {
       db.commit();
   }
}

QSqlTableModel *EmployeeDataModel::initializeViewModel() {

    //TODO: id als locale Konstante

    QSqlRelationalTableModel *model = new QSqlRelationalTableModel(this);
    model->setTable(QLatin1String("employee_view"));
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    model->setHeaderData(POS_EMPLOYEE_FIRSTNAME, Qt::Horizontal, QObject::tr("Firstname"));
    model->setHeaderData(POS_EMPLOYEE_LASTNAME, Qt::Horizontal, QObject::tr("Lastname"));

    model->select();

    return model;
}

QSqlRelationalTableModel *EmployeeDataModel::initializeRelationalModel() {

    //TODO: id als locale Konstante

    QSqlRelationalTableModel *model = new QSqlRelationalTableModel(this);
    model->setTable(QLatin1String("employee"));
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    model->setRelation(POS_EMPLOYEE_TITLE_ID, QSqlRelation(QLatin1String("title"),
                                                           QLatin1String("title_id"),
                                                           QLatin1String("name")));

    model->setRelation(POS_EMPLOYEE_ADDRESS_ID, QSqlRelation(QLatin1String("address"),
                                                             QLatin1String("address_id"),
                                                             QLatin1String("address")));

    model->setRelation(POS_EMPLOYEE_DEPARTMENT_ID, QSqlRelation(QLatin1String("department"),
                                                    QLatin1String("department_id"),
                                                    QLatin1String("name")));

    model->setRelation(POS_EMPLOYEE_FUNCTION_ID, QSqlRelation(QLatin1String("function"),
                                                  QLatin1String("function_id"),
                                                  QLatin1String("name")));


    model->setRelation(POS_EMPLOYEE_COMPUTER_ID, QSqlRelation(QLatin1String("computer"),
                                                  QLatin1String("computer_id"),
                                                  QLatin1String("network_name")));


    model->setRelation(POS_EMPLOYEE_PRINTER_ID, QSqlRelation(QLatin1String("printer"),
                                                  QLatin1String("printer_id"),
                                                  QLatin1String("network_name")));


    model->setRelation(POS_EMPLOYEE_PHONE_ID, QSqlRelation(QLatin1String("phone"),
                                               QLatin1String("phone_id"),
                                                QLatin1String("number")));

    model->setRelation(POS_EMPLOYEE_MOBILE_ID, QSqlRelation(QLatin1String("mobile"),
                                                            QLatin1String("mobile_id"),
                                                            QLatin1String("number")));

    model->setRelation(POS_EMPLOYEE_FAX_ID, QSqlRelation(QLatin1String("fax"),
                                                         QLatin1String("fax_id"),
                                                        QLatin1String("number")));

    model->setHeaderData(POS_EMPLOYEE_ID, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(POS_EMPLOYEE_NR, Qt::Horizontal, QObject::tr("Emp.Number"));
    model->setHeaderData(POS_EMPLOYEE_GENDER, Qt::Horizontal, QObject::tr("Gender"));
    model->setHeaderData(POS_EMPLOYEE_TITLE_ID, Qt::Horizontal, QObject::tr("Title"));
    model->setHeaderData(POS_EMPLOYEE_FIRSTNAME, Qt::Horizontal, QObject::tr("Firstname"));
    model->setHeaderData(POS_EMPLOYEE_LASTNAME, Qt::Horizontal, QObject::tr("Lastname"));
    model->setHeaderData(POS_EMPLOYEE_ADDRESS_ID, Qt::Horizontal, QObject::tr("address"));
    model->setHeaderData(POS_EMPLOYEE_BIRTHDAY, Qt::Horizontal, QObject::tr("Birthday"));
    model->setHeaderData(POS_EMPLOYEE_EMAIL, Qt::Horizontal, QObject::tr("EMail"));
    model->setHeaderData(POS_EMPLOYEE_DATACARE, Qt::Horizontal, QObject::tr("Datacare"));
    model->setHeaderData(POS_EMPLOYEE_ACTIVE, Qt::Horizontal, QObject::tr("Active"));
    model->setHeaderData(POS_EMPLOYEE_STARTDATE, Qt::Horizontal, QObject::tr("StartDate"));
    model->setHeaderData(POS_EMPLOYEE_ENDDATE, Qt::Horizontal, QObject::tr("EndDate"));
    model->setHeaderData(POS_EMPLOYEE_DEPARTMENT_ID, Qt::Horizontal, QObject::tr("Department"));
    model->setHeaderData(POS_EMPLOYEE_FUNCTION_ID, Qt::Horizontal, QObject::tr("Function"));
    model->setHeaderData(POS_EMPLOYEE_COMPUTER_ID, Qt::Horizontal, QObject::tr("Computer"));
    model->setHeaderData(POS_EMPLOYEE_PRINTER_ID, Qt::Horizontal, QObject::tr("Printer"));
    model->setHeaderData(POS_EMPLOYEE_PHONE_ID, Qt::Horizontal, QObject::tr("Phone"));
    model->setHeaderData(POS_EMPLOYEE_MOBILE_ID, Qt::Horizontal, QObject::tr("Mobile"));
    model->setHeaderData(POS_EMPLOYEE_FAX_ID, Qt::Horizontal, QObject::tr("Fax"));
    model->setHeaderData(POS_EMPLOYEE_EMPLOYEE_ACCOUNT_ID, Qt::Horizontal, QObject::tr("Accounts"));
    model->setHeaderData(POS_EMPLOYEE_EMPLOYEE_DOCUMENT_ID, Qt::Horizontal, QObject::tr("Documents"));
    model->setHeaderData(POS_EMPLOYEE_LAST_UPDATE, Qt::Horizontal, QObject::tr("Last Update"));

    model->select();

    return model;
}

QSqlRelationalTableModel *EmployeeDataModel::initializeInputDataModel() {

    QSqlRelationalTableModel *model = new QSqlRelationalTableModel(this, this->db);
    model->setTable(QLatin1String("employee"));

   return model;
}

QSqlTableModel *EmployeeDataModel::initializeTableModel() {
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable(QLatin1String("employee"));
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->setHeaderData(POS_EMPLOYEE_ID, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(POS_EMPLOYEE_NR, Qt::Horizontal, QObject::tr("Emp.Number"));
    model->setHeaderData(POS_EMPLOYEE_GENDER, Qt::Horizontal, QObject::tr("Gender"));
    model->setHeaderData(POS_EMPLOYEE_TITLE_ID, Qt::Horizontal, QObject::tr("Title"));
    model->setHeaderData(POS_EMPLOYEE_FIRSTNAME, Qt::Horizontal, QObject::tr("Firstname"));
    model->setHeaderData(POS_EMPLOYEE_LASTNAME, Qt::Horizontal, QObject::tr("Lastname"));
    model->setHeaderData(POS_EMPLOYEE_ADDRESS_ID, Qt::Horizontal, QObject::tr("address"));
    model->setHeaderData(POS_EMPLOYEE_BIRTHDAY, Qt::Horizontal, QObject::tr("Birthday"));
    model->setHeaderData(POS_EMPLOYEE_EMAIL, Qt::Horizontal, QObject::tr("EMail"));
    model->setHeaderData(POS_EMPLOYEE_DATACARE, Qt::Horizontal, QObject::tr("Datacare"));
    model->setHeaderData(POS_EMPLOYEE_ACTIVE, Qt::Horizontal, QObject::tr("Active"));
    model->setHeaderData(POS_EMPLOYEE_STARTDATE, Qt::Horizontal, QObject::tr("StartDate"));
    model->setHeaderData(POS_EMPLOYEE_ENDDATE, Qt::Horizontal, QObject::tr("EndDate"));
    model->setHeaderData(POS_EMPLOYEE_DEPARTMENT_ID, Qt::Horizontal, QObject::tr("Department"));
    model->setHeaderData(POS_EMPLOYEE_FUNCTION_ID, Qt::Horizontal, QObject::tr("Function"));
    model->setHeaderData(POS_EMPLOYEE_COMPUTER_ID, Qt::Horizontal, QObject::tr("Computer"));
    model->setHeaderData(POS_EMPLOYEE_PRINTER_ID, Qt::Horizontal, QObject::tr("Printer"));
    model->setHeaderData(POS_EMPLOYEE_PHONE_ID, Qt::Horizontal, QObject::tr("Phone"));
    model->setHeaderData(POS_EMPLOYEE_MOBILE_ID, Qt::Horizontal, QObject::tr("Mobile"));
    model->setHeaderData(POS_EMPLOYEE_FAX_ID, Qt::Horizontal, QObject::tr("Fax"));
    model->setHeaderData(POS_EMPLOYEE_EMPLOYEE_ACCOUNT_ID, Qt::Horizontal, QObject::tr("Accounts"));
    model->setHeaderData(POS_EMPLOYEE_EMPLOYEE_DOCUMENT_ID, Qt::Horizontal, QObject::tr("Documents"));
    model->setHeaderData(POS_EMPLOYEE_LAST_UPDATE, Qt::Horizontal, QObject::tr("Last Update"));

    model->select();

    return model;
}

void EmployeeDataModel::setFirstname(QString *_firstname) {
    this->firstname = _firstname;
}

void EmployeeDataModel::setLastname(QString *_lastname) {
    this->lastname = _lastname;
}

void EmployeeDataModel::readAllRecords()
{

    QSqlQueryModel model;
    model.setQuery(QLatin1String("SELECT * FROM employee"));

    int colunmCount = model.columnCount();
    int rowCount = model.rowCount();


    QSqlRecord rec = model.record();
    // int recCount = rec.count();


    for (int i=0; i<rowCount; i++) {
        qDebug() << "Record : " << i;
        rec = model.record(i);
        for (int j=0; j<colunmCount; j++) {
            QString value = rec.value(j).toString();
            qDebug() << "ColumnCount : " << j << " - Value  = " << value;
        }
    }
}


QTextDocument *EmployeeDataModel::createSheet() {
    QTextDocument *document = new QTextDocument;

    return document;
}

QString EmployeeDataModel::generateTableString(QAbstractTableModel *model, QString header) {
    QString outString;
    int columnCount = model->columnCount();
    int rowCount = model->rowCount();
    qDebug() << "Header : " << header << " Columns : " << columnCount << " Rows : " << rowCount;

    QList<int> set;
    set.append(POS_EMPLOYEE_FIRSTNAME);
    set.append(POS_EMPLOYEE_LASTNAME);
    set.append(POS_EMPLOYEE_DEPARTMENT_ID);
    set.append(POS_EMPLOYEE_FUNCTION_ID);
    set.append(POS_EMPLOYEE_COMPUTER_ID);
    set.append(POS_EMPLOYEE_PRINTER_ID);
    set.append(POS_EMPLOYEE_EMAIL);
    set.append(POS_EMPLOYEE_PHONE_ID);
    set.append(POS_EMPLOYEE_FAX_ID);
    set.append(POS_EMPLOYEE_MOBILE_ID);

    // Document Title
    outString = QLatin1String("<h1>");
    outString += header;
    outString += QLatin1String("</h1>");
    outString += QLatin1String("<hr />");
    outString += QLatin1String("<table width=\"100%\" cellspacing=\"0\" class=\"tbl\">");
    outString += QLatin1String("<thead> <tr>");


    foreach (const int i, set) {
        qDebug() << "int i = " << i;
        outString += QLatin1String("<th>");
        outString.append(model->headerData(i, Qt::Horizontal).toString());
        outString += QLatin1String("</th>");
    }
    outString += QLatin1String("</tr> </thead>");


    for (int i=1; i<rowCount; i++) {
        outString += QLatin1String("<tr>");
        foreach (const int j, set) {
            outString += QLatin1String("<td>");
            QModelIndex ind(model->index(i, j));
            outString.append(ind.data(Qt::DisplayRole).toString());
            outString += QLatin1String("</td>");
        }
        outString += QLatin1String("</tr>");
    }

    // Close Table
    outString += QLatin1String("</table>");
    return outString;

}
