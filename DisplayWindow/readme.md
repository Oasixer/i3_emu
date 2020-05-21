* This subdirectory contains some classes for containing the actual tree layout of the windows, ie.
  
  Workspace 1 (horizontal)
        Window foo@bar: ~
        Split (vertical)
                Window foo@bar: ~
                Window foo@bar: ~
                
  
# Classes
Component: base component. only does stuff that EVERY component must do, ie. rectangle math, also getptr()

Window(extends Component): A leaf node containing an actual hwnd to display, resize, etc

Composite (extends Component): A generic composite which contains a vector of components, each of which could be a composite

Workspace(extends Composite): A composite node which contains components, each of which could be a composite.
                         Workspaces are the lowest level of the i3 organization tree

Horizontal(extends Composite): A composite node which contains components, each of which could be a composite.
                          Horizontal split layout.

Vertical(extends Composite): A composite node which contains components, each of which could be a composite.
                        Vertical split layout.

Tabbed (extends Composite): A composite node which contains components, each of which could be a composite.
                       Tabbed layout.
