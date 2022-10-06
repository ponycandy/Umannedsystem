#ifndef VIDEO_DISPLAY_MANAGER_H
#define VIDEO_DISPLAY_MANAGER_H

#include <QWidget>

namespace Ui {
class video_display_manager;
}

class video_display_manager : public QWidget
{
    Q_OBJECT

public:
    explicit video_display_manager(QWidget *parent = nullptr);
    ~video_display_manager();

private:
    Ui::video_display_manager *ui;
};

#endif // VIDEO_DISPLAY_MANAGER_H
