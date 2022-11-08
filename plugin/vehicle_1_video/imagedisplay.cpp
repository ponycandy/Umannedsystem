#include "imagedisplay.h"
#include "QPainter"
ImageDisplay::ImageDisplay(QWidget *parent) :
    QWidget(parent),
   m_image(NULL)
{
    m_image=nullptr;
    m_display_flag=0;
   // setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

ImageDisplay::~ImageDisplay()
{
}

void ImageDisplay::setImage(QImage *image)
{
    m_display_flag=1;
    m_image = image;
    repaint();
}

void ImageDisplay::change_size(int w, int h)
{
    setFixedSize(w,h);
}

void ImageDisplay::slotOnFrameImageNotify(IMAGE_DATA::_IMAGEDATA data)
{
        setImage(data.sp_t_image.data());

}

void ImageDisplay::paintEvent(QPaintEvent *event)
{
    if (!m_image)
    { return; }
    QPainter painter(this);
    painter.drawImage(rect(), *m_image, m_image->rect());
}
