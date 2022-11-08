#ifndef VIDEO_DISPLAY_WIDGET_H
#define VIDEO_DISPLAY_WIDGET_H

#include <QWidget>

namespace Ui {
class video_display_widget;
}

class video_display_widget : public QWidget
{
    Q_OBJECT

public:
    explicit video_display_widget(QWidget *parent = nullptr);
    ~video_display_widget();

private:
    Ui::video_display_widget *ui;
};

#endif // VIDEO_DISPLAY_WIDGET_H
