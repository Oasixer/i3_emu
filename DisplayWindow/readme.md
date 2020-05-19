* This subdirectory contains some classes for containing the actual tree layout of the windows, ie.
  
  Workspace 1 (horizontal)
        Window foo@bar: ~
        Split (vertical)
                Window foo@bar: ~
                Window foo@bar: ~
                
  
# Classes
Base: base component. only does stuff that EVERY component must do, ie. rectangle math?

Window(extends Base): A leaf node containing an actual hwnd to display, resize, etc

Workspace(extends Base): A composite node which contains components, each of which could be a composite.
                         Workspaces are the lowest level of the i3 organization tree

Horizontal(extends Base): A composite node which contains components, each of which could be a composite.
                          Horizontal split layout.

Vertical(extends Base): A composite node which contains components, each of which could be a composite.
                        Vertical split layout.

Tabbed (extends Base): A composite node which contains components, each of which could be a composite.
                       Tabbed layout.
