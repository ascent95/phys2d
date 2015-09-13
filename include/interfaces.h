#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

class IScreen
{
public:
    virtual ~IScreen() {}
    virtual bool init( const char *title ) = 0;
    virtual void quit() = 0;
    virtual void render() = 0;
    virtual void clear() = 0;
    virtual void handle_events() = 0;
    virtual bool is_running() = 0;
};

class IWorld
{
public:
    virtual ~IWorld() {}
    virtual void run() = 0;
    
    virtual void update() = 0;
};

#endif 