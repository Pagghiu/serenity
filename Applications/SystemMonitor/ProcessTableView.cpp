#include "ProcessTableView.h"
#include "ProcessModel.h"
#include <LibGUI/GSortingProxyModel.h>
#include <stdio.h>

ProcessTableView::ProcessTableView(GWidget* parent)
    : GTableView(parent)
{
    set_size_columns_to_fit_content(true);
    set_model(GSortingProxyModel::create(ProcessModel::create()));
    model()->set_key_column_and_sort_order(ProcessModel::Column::CPU, GSortOrder::Descending);
    refresh();

    on_selection = [this](auto&) {
        if (on_process_selected)
            on_process_selected(selected_pid());
    };
}

ProcessTableView::~ProcessTableView()
{
}

void ProcessTableView::refresh()
{
    model()->update();
}

pid_t ProcessTableView::selected_pid() const
{
    if (selection().is_empty())
        return -1;
    return model()->data(model()->index(selection().first().row(), ProcessModel::Column::PID), GModel::Role::Sort).as_int();
}
