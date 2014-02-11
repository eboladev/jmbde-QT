/*
 * pctypedatamodel.cpp - PCTypeDataModel
 * jmbde
 *
 * Created by Jürgen Mülbert on 23.11.2013
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


#include "pctypedatamodel.h"

/**
 * @brief PCTypeDataModel::PCTypeDataModel
 * @param parent
 */
PCTypeDataModel::PCTypeDataModel(QObject *parent) :
    CommonDataModel(parent)
{
}

/**
 * @brief PCTypeDataModel::~PCTypeDataModel
 */
PCTypeDataModel::~PCTypeDataModel()
{

}

/**
 * @brief PCTypeDataModel::createDataTable
 */
bool PCTypeDataModel::createDataTable()
{
    bool ret;

    ret = CommonDataModel::createDataTable(this->tableName);

    return ret;
}

/**
 * @brief PCTypeDataModel::initializeTableModel
 */
QSqlTableModel *PCTypeDataModel::initializeTableModel()
{
    QSqlTableModel *tableModel;

    tableModel = CommonDataModel::initializeTableModel(this->tableName);

    return tableModel;
}

/**
 * @brief PCTypeDataModel::initializeRelationalModel
 */
QSqlRelationalTableModel *PCTypeDataModel::initializeRelationalModel()
{
    QSqlRelationalTableModel *tableModel;

    tableModel = CommonDataModel::initializeRelationalModel(this->tableName);

    return tableModel;
}