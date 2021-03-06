/*
 * ComputerDataModel.cpp
 * jmbde
 *
 * Copyright (c) 2013,2014 Jürgen Mülbert. All rights reserved.
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

#include "computerdatamodel.h"


ComputerDataModel::ComputerDataModel(QObject *parent) : DataModell(parent)
{
}


ComputerDataModel::~ComputerDataModel() {

}

void ComputerDataModel::addDataSet() {
    QSqlQuery query;

    QString sqlString = QLatin1String("insert into computer(pcnr, name) values( ");

    sqlString.append(QLatin1String("'"));
    sqlString.append(pcnr);
    sqlString.append(QLatin1String("' , '"));
    sqlString.append(name);
    sqlString.append(QLatin1String("');"));
    bool ret = query.exec(sqlString);
    if (ret == false) {
        qDebug() << sqlString.toLatin1();
        qDebug() << db.lastError();
    } else {
        db.commit();
    }
}


QSqlRelationalTableModel *ComputerDataModel::initializeRelationalModel() {
    //TODO: id als locale Konstante

    QSqlRelationalTableModel *model = new QSqlRelationalTableModel(this);
    model->setTable(QLatin1String("computer"));
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    model->setRelation(POS_COMPUTER_DEVICENAME_ID, QSqlRelation(QLatin1String("devicename"),
                                                               QLatin1String("devicename_id"),
                                                               QLatin1String("name")));

    model->setRelation(POS_COMPUTER_DEVICETYPE_ID, QSqlRelation(QLatin1String("devicetype"),
                                                               QLatin1String("devicetype_id"),
                                                               QLatin1String("name")));

    model->setRelation(POS_COMPUTER_EMPLOYEE_ID, QSqlRelation(QLatin1String("employee"),
                                                  QLatin1String("employee_id"),
                                                  QLatin1String("lastname")));

    model->setRelation(POS_COMPUTER_PLACE_ID, QSqlRelation(QLatin1String("place"),
                                                  QLatin1String("place_id"),
                                                  QLatin1String("name")));

    model->setRelation(POS_COMPUTER_DEPARTMENT_ID, QSqlRelation(QLatin1String("department"),
                                                    QLatin1String("department_id"),
                                                    QLatin1String("name")));

    model->setRelation(POS_COMPUTER_MANUFACTURER_ID, QSqlRelation(QLatin1String("manufacturer"),
                                               QLatin1String("manufacturer_id"),
                                               QLatin1String("name")));

    model->setRelation(POS_COMPUTER_INVENTORY_ID, QSqlRelation(QLatin1String("inventory"),
                                                 QLatin1String("inventory_id"),
                                                 QLatin1String("number")));


    model->setRelation(POS_COMPUTER_PROCESSOR_ID, QSqlRelation(QLatin1String("processor"),
                                                               QLatin1String("processor_id"),
                                                               QLatin1String("name")));

    model->setRelation(POS_COMPUTER_OS_ID, QSqlRelation(QLatin1String("os"),
                                                        QLatin1String("os_id"),
                                                        QLatin1String("name")));

    model->setRelation(POS_COMPUTER_COMPUTERSOFTWARE_ID, QSqlRelation(QLatin1String("computersoftware"),
                                                        QLatin1String("computersoftware_id"),
                                                        QLatin1String("software_id")));

    model->setRelation(POS_COMPUTER_PRINTER_ID, QSqlRelation(QLatin1String("printer"),
                                                QLatin1String("printer_id"),
                                                QLatin1String("network_name")));

    model->setHeaderData(POS_COMPUTER_ID, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(POS_COMPUTER_DEVICENAME_ID, Qt::Horizontal, QObject::tr("Dev.Name"));
    model->setHeaderData(POS_COMPUTER_SERIALNUMBER, Qt::Horizontal, QObject::tr("S/N"));
    model->setHeaderData(POS_COMPUTER_SERVICE_TAG, Qt::Horizontal, QObject::tr("Service Tag"));
    model->setHeaderData(POS_COMPUTER_SERVICE_NUMBER, Qt::Horizontal, QObject::tr("Service Number"));
    model->setHeaderData(POS_COMPUTER_MEMORY, Qt::Horizontal, QObject::tr("Memory"));
    model->setHeaderData(POS_COMPUTER_NETWORK, Qt::Horizontal, QObject::tr("Network"));
    model->setHeaderData(POS_COMPUTER_NETWORK_NAME, Qt::Horizontal, QObject::tr("Network Name"));
    model->setHeaderData(POS_COMPUTER_NETWORK_IPADDRESS, Qt::Horizontal, QObject::tr("IP Address"));
    model->setHeaderData(POS_COMPUTER_ACTIVE, Qt::Horizontal, QObject::tr("Active"));
    model->setHeaderData(POS_COMPUTER_REPLACE, Qt::Horizontal, QObject::tr("Replace"));
    model->setHeaderData(POS_COMPUTER_DEVICETYPE_ID, Qt::Horizontal, QObject::tr("Device Type"));
    model->setHeaderData(POS_COMPUTER_EMPLOYEE_ID, Qt::Horizontal, QObject::tr("Employee"));
    model->setHeaderData(POS_COMPUTER_PLACE_ID, Qt::Horizontal, QObject::tr("Place"));
    model->setHeaderData(POS_COMPUTER_DEPARTMENT_ID, Qt::Horizontal, QObject::tr("Department"));
    model->setHeaderData(POS_COMPUTER_MANUFACTURER_ID, Qt::Horizontal, QObject::tr("Manufacturer"));
    model->setHeaderData(POS_COMPUTER_INVENTORY_ID, Qt::Horizontal, QObject::tr("Inventory"));
    model->setHeaderData(POS_COMPUTER_PROCESSOR_ID, Qt::Horizontal, QObject::tr("Processor"));
    model->setHeaderData(POS_COMPUTER_OS_ID, Qt::Horizontal, QObject::tr("Operation System"));
    model->setHeaderData(POS_COMPUTER_COMPUTERSOFTWARE_ID, Qt::Horizontal, QObject::tr("Software"));
    model->setHeaderData(POS_COMPUTER_PRINTER_ID, Qt::Horizontal, QObject::tr("Printer"));
    model->setHeaderData(POS_COMPUTER_LAST_UPDATE, Qt::Horizontal, QObject::tr("Last Update"));

    model->select();

    return model;
}


QSqlTableModel *ComputerDataModel::initializeTableModel() {
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable(QLatin1String("computer"));
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    model->setHeaderData(POS_COMPUTER_ID, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(POS_COMPUTER_DEVICENAME_ID, Qt::Horizontal, QObject::tr("Dev.Name"));
    model->setHeaderData(POS_COMPUTER_SERIALNUMBER, Qt::Horizontal, QObject::tr("S/N"));
    model->setHeaderData(POS_COMPUTER_SERVICE_TAG, Qt::Horizontal, QObject::tr("Service Tag"));
    model->setHeaderData(POS_COMPUTER_SERVICE_NUMBER, Qt::Horizontal, QObject::tr("Service Number"));
    model->setHeaderData(POS_COMPUTER_MEMORY, Qt::Horizontal, QObject::tr("Memory"));
    model->setHeaderData(POS_COMPUTER_NETWORK, Qt::Horizontal, QObject::tr("Network"));
    model->setHeaderData(POS_COMPUTER_NETWORK_NAME, Qt::Horizontal, QObject::tr("Network Name"));
    model->setHeaderData(POS_COMPUTER_NETWORK_IPADDRESS, Qt::Horizontal, QObject::tr("IP Address"));
    model->setHeaderData(POS_COMPUTER_ACTIVE, Qt::Horizontal, QObject::tr("Active"));
    model->setHeaderData(POS_COMPUTER_REPLACE, Qt::Horizontal, QObject::tr("Replace"));
    model->setHeaderData(POS_COMPUTER_DEVICETYPE_ID, Qt::Horizontal, QObject::tr("Device Type"));
    model->setHeaderData(POS_COMPUTER_EMPLOYEE_ID, Qt::Horizontal, QObject::tr("Employee"));
    model->setHeaderData(POS_COMPUTER_PLACE_ID, Qt::Horizontal, QObject::tr("Place"));
    model->setHeaderData(POS_COMPUTER_DEPARTMENT_ID, Qt::Horizontal, QObject::tr("Department"));
    model->setHeaderData(POS_COMPUTER_MANUFACTURER_ID, Qt::Horizontal, QObject::tr("Manufacturer"));
    model->setHeaderData(POS_COMPUTER_INVENTORY_ID, Qt::Horizontal, QObject::tr("Inventory"));
    model->setHeaderData(POS_COMPUTER_PROCESSOR_ID, Qt::Horizontal, QObject::tr("Processor"));
    model->setHeaderData(POS_COMPUTER_OS_ID, Qt::Horizontal, QObject::tr("Operation System"));
    model->setHeaderData(POS_COMPUTER_COMPUTERSOFTWARE_ID, Qt::Horizontal, QObject::tr("Software"));
    model->setHeaderData(POS_COMPUTER_PRINTER_ID, Qt::Horizontal, QObject::tr("Printer"));
    model->setHeaderData(POS_COMPUTER_LAST_UPDATE, Qt::Horizontal, QObject::tr("Last Update"));

    model->select();

    return model;

}

QString ComputerDataModel::generateTableString(QAbstractTableModel *model, QString header) {
    QString outString;
    int columnCount = model->columnCount();
    int rowCount = model->rowCount();
    qDebug() << "Header : " << header << " Columns : " << columnCount << " Rows : " << rowCount;

    QList<int> set;
    set.append(POS_COMPUTER_DEVICENAME_ID);
    set.append(POS_COMPUTER_DEVICETYPE_ID);
    set.append(POS_COMPUTER_NETWORK_NAME);
    set.append(POS_COMPUTER_MANUFACTURER_ID);
    set.append(POS_COMPUTER_EMPLOYEE_ID);
    set.append(POS_COMPUTER_DEPARTMENT_ID);
    set.append(POS_COMPUTER_PLACE_ID);
    set.append(POS_COMPUTER_PRINTER_ID);

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

