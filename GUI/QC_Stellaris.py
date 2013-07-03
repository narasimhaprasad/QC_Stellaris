from kivy.app import App
from kivy.animation import Animation
from kivy.uix.floatlayout import FloatLayout
from kivy.uix.tabbedpanel import TabbedPanel, TabbedPanelHeader
from kivy.factory import Factory

class StandingHeader(TabbedPanelHeader):
    pass


class CloseableHeader(TabbedPanelHeader):
    pass

Factory.register('StandingHeader', cls = StandingHeader)
Factory.register('CloseableHeader', cls = CloseableHeader)

from kivy.lang import Builder

Builder.load_string('''
<TabShowcase>
    but: _but
    Button:
        id: _but
        text: ' Quadcopter project with Stellaris Launchpad \\n Author: Narasimha Prasad Prabhu \\n Processor: LM4F120H5QR \\n Barometer: BMP085 \\n Digital Compass: HMC5883l \\n All code is under the Creative Commons Attribution Non-Commercial-ShareAlike \\n Exceptions: startup_gcc.c. Provided by TI LM4F.ld. Provided by TI \\n QC_I2C.c,h: Initial code by aBugsWorstNightmare \\n Please follow the individual licences for those files \\n Includes: Stellarisware CMSIS gcc-arm Project \\n Project Site: https://sites.google.com/site/narasimhaweb/projects/quadcopter-with-stellaris-launchpad'
        on_release: root.show_tab()

<StandingHeader>
    color: 0,0,0,0
    Scatter:
        do_translation: False
        do_scale: False
        do_rotation: False
        auto_bring_to_front: False
        rotation: 70
        size_hint: None, None
        size: lbl.size
        center_x: root.center_x
        center_y: root.center_y
        Label:
            id: lbl
            text: root.text
            size: root.size
            pos: 0,0

<Panel>
    tab_pos: 'bottom_left'
    default_tab_cls: settings.__class__
    do_default_tab: False

    TabbedPanelItem:
        id: settings
        text: 'Settings'
        BubbleButton
            text: 'In development'
    TabbedPanelItem:
        text: 'GUI'
        BubbleButton:
            text: 'switch to settings'
            on_press: root.switch_to(settings)
    TabbedPanelItem:
        text: 'Other'
        BubbleButton:
            text: 'switch to settings'
            on_press: root.switch_to(settings)
''')

class Tp(TabbedPanel):

    #override tab switching method to animate on tab switch
    def switch_to(self, header):
        anim = Animation(opacity=0, d=.24, t='in_out_quad')

        def start_anim(_anim, child, in_complete, *lt):
            _anim.start(child)

        def _on_complete(*lt):
            if header.content:
                header.content.opacity = 0
                anim = Animation(opacity=1, d=.43, t='in_out_quad')
                start_anim(anim, header.content, True)
            super(Tp, self).switch_to(header)

        anim.bind(on_complete = _on_complete)
        if self.current_tab.content:
            start_anim(anim, self.current_tab.content, False)
        else:
            _on_complete()   

class Panel(Tp):
    pass
            
class TabShowcase(FloatLayout):
    
    def show_tab(self):
        self.tab = tab = Panel()
        self.add_widget(tab)
    
           
class QC_Stellaris(App):

    def build(self):
        return TabShowcase()

if __name__ == '__main__':
    QC_Stellaris().run()