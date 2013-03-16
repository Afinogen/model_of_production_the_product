/*
 * container.cpp
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#include "container.h"

Container::Container()
{

}

Container::~Container()
{
    array_data_.clear();
}

void Container::AddRequest(Request *data)
{
    array_data_.push_back(data);
}

Request *Container::GetRequest(const int idx) const
{
    if (idx < 0 || idx >= array_data_.size()) return NULL;

    return array_data_[idx];
}

int Container::GetSizeContainer() const
{
    return array_data_.size();
}

void Container::DeleteRequest(const int idx)
{
    if (idx < 0 || idx >= array_data_.size()) return;

    DeleteRequest(array_data_[idx]);
}

void Container::DeleteRequest(const Request *data)
{
    if (data == NULL) return;

    vector<Request*> ndata;
    for (unsigned int i = 0; i < array_data_.size(); i++)
        if (array_data_[i]->GetId() != data->GetId()) ndata.push_back(
                array_data_[i]);
    array_data_.clear();
    for (unsigned int i = 0; i < ndata.size(); i++)
        array_data_.push_back(ndata[i]);
}

void Container::ClearContainer()
{
    array_data_.clear();
}
