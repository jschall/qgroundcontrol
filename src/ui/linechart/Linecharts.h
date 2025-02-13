#ifndef LINECHARTS_H
#define LINECHARTS_H

#include <QStackedWidget>
#include <QMap>

#include "LinechartWidget.h"
#include "UASInterface.h"

class Linecharts : public QStackedWidget
{
    Q_OBJECT
public:
    explicit Linecharts(QWidget *parent = 0);

signals:
    /** @brief This signal is emitted once a logfile has been finished writing */
    void logfileWritten(QString fileName);
    void visibilityChanged(bool visible);

public slots:
    /** @brief Select plot for one system */
    void selectSystem(int systemid);
    /** @brief Add a new system to the list of plots */
    void addSystem(UASInterface* uas);

protected:

    QMap<int, LinechartWidget*> plots;
    bool active;
    /** @brief Start updating widget */
    void showEvent(QShowEvent* event);
    /** @brief Stop updating widget */
    void hideEvent(QHideEvent* event);

};

#endif // LINECHARTS_H
