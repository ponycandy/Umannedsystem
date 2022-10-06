#pragma once

#include <QWidget>

class MainWindow;
class soyImageButton;
class soySystemButtonBar;

class TitleWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief TitleWidget
     * @param mainWindow
     * @param parent
     */
    explicit TitleWidget(MainWindow *mainWindow, QWidget *parent = nullptr);

    ~TitleWidget();


protected:
    /**
     * @brief mousePressEvent
     * @param event
     */
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    /**
     * @brief mouseReleaseEvent
     * @param event
     */
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    /**
     * @brief mouseMoveEvent
     * @param event
     */
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    /**
     * @brief mouseDoubleClickEvent
     * @param event
     */
    void mouseDoubleClickEvent(QMouseEvent *event) Q_DECL_OVERRIDE;


private:
    /**
     * @brief setupUi
     */
    void setupUi();

    /**
     * @brief releaseUi
     */
    void releaseUi();

signals:
    /**
     * @brief menuRequested
     */
    void menuRequested();

private:
    /**
     * @brief m_mainWindow
     */
    MainWindow *m_mainWindow;

    /**
     * @brief m_menuButton
     */
  //  soyImageButton *m_menuButton;

    /**
     * @brief m_systemButtonBar
     */
   // soySystemButtonBar *m_systemButtonBar;

    /**
     * @brief m_pressPoint
     */
    QPoint m_pressPoint;

    /**
     * @brief m_movePoint
     */
    QPoint m_movePoint;

    /**
     * @brief m_isMove
     */
    bool m_isMove;

    /**
     * @brief m_mousePressed
     */
    bool m_mousePressed;
};
