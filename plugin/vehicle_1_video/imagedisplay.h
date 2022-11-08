#ifndef IMAGEDISPLAY_H
#define IMAGEDISPLAY_H

#include <QWidget>
#include <defines/Vehicle1_data.h>
namespace Ui {
class ImageDisplay;
}

class ImageDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit ImageDisplay(QWidget *parent = nullptr);
    ~ImageDisplay();
    void setImage(QImage* image);
    void change_size(int w,int h);
    int m_display_flag;
    QImage* m_image;
public slots:
    void slotOnFrameImageNotify(IMAGE_DATA::_IMAGEDATA data);
protected:
    void paintEvent(QPaintEvent* event);
};

#endif // IMAGEDISPLAY_H
