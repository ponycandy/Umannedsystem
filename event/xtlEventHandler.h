

#ifndef XTLEVENTHANDLER_H
#define XTLEVENTHANDLER_H

#include "xtlEvent.h"

/**
 * \ingroup EventAdmin
 *
 * Listener for Events.
 *
 * <p>
 * <code>xtlEventHandler</code> objects are registered with the Framework service
 * registry and are notified with an <code>xtlEvent</code> object when an event
 * is sent or posted.
 * <p>
 * <code>xtlEventHandler</code> objects can inspect the received
 * <code>xtlEvent</code> object to determine its topic and properties.
 *
 * <p>
 * <code>xtlEventHandler</code> objects must be registered with a service
 * property {@link xtlEventConstants#EVENT_TOPIC} whose value is the list of topics
 * in which the event handler is interested.
 * <p>
 * For example:
 *
 * \code
 * QStringList topics("com/isv/&#42;");
 * xtlDictionary props;
 * props.insert(xtlEventConstants::EVENT_TOPIC, topics);
 * context->registerService<xtlEventHandler>(this, props);
 * \endcode
 *
 * Event Handler services can also be registered with an
 * {@link xtlEventConstants#EVENT_FILTER} service property to further filter the
 * events. If the syntax of this filter is invalid, then the Event Handler must
 * be ignored by the Event Admin service. The Event Admin service should log a
 * warning.
 * <p>
 * Security Considerations. Plugins wishing to monitor <code>xtlEvent</code>
 * objects will require <code>xtlServicePermission[xtlEventHandler,REGISTER]</code>
 * to register a <code>xtlEventHandler</code> service. The plugin must also have
 * <code>xtlTopicPermission[topic,SUBSCRIBE]</code> for the topic specified in
 * the event in order to receive the event.
 *
 * @see xtlEvent
 *
 * @remarks This class is thread safe.
 */
struct xtlEventHandler
{
  virtual ~xtlEventHandler() {}

  /**
   * Called by the {@link xtlEventAdmin} service to notify the listener of an
   * event.
   *
   * @param event The event that occurred.
   */
  virtual void handleEvent(const xtlEvent& event) = 0;
};

Q_DECLARE_INTERFACE(xtlEventHandler, "xyz.xtal.service.event.EventHandler")

#endif // XTLEVENTHANDLER_H
