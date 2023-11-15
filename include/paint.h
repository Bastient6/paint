/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** paint
*/

#ifndef PAINT_H_
    #define PAINT_H_
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <SFML/System/Time.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/System/Vector3.h>
    #include <sys/wait.h>
    #include "drawing/drawing.h"
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/sysmacros.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <stdio.h>
    #include <pwd.h>
    #include <grp.h>
    #include <errno.h>
    #include <math.h>
    #include <time.h>

    enum e_gui_state {
        NONE = 0 ,
        HOVER ,
        PRESSED ,
        RELEASED
    };

    #define IS_HOVER(button) (button->state == PRESSED)
    #define IS_PRESSED(button) (button->state == PRESSED)
    #define IS_RELEASED(button) (button->state == PRESSED)
    #define RED sfColor_fromRGB(255, 0, 0)
    #define GREEN sfColor_fromRGB(0, 255, 0)
    #define BLUE sfColor_fromRGB(0, 0, 255)
    #define YELLOW sfColor_fromRGB(255, 255, 0)
    #define PURPLE sfColor_fromRGB(255, 0, 255)
    #define CYAN sfColor_fromRGB(0, 255, 255)
    #define WHITE sfColor_fromRGB(255, 255, 255)
    #define BLACK sfColor_fromRGB(0, 0, 0)
    #define GREY sfColor_fromRGB(128, 128, 128)
    #define LIGHT_GREY sfColor_fromRGB(211, 211, 211)
    #define DARK_GREY sfColor_fromRGB(169, 169, 169)
    #define DARKEST_GREY sfColor_fromRGB(105, 105, 105)
    #define ORANGE sfColor_fromRGB(255, 165, 0)
    #define BROWN sfColor_fromRGB(165, 42, 42)
    #define PINK sfColor_fromRGB(255, 192, 203)
    #define TURQUOISE sfColor_fromRGB(64, 224, 208)

    typedef struct button_s {
        sfRectangleShape *rect ;
        sfBool (* is_clicked )
        ( struct button_s * , sfMouseButtonEvent *) ;
        sfBool (* is_hover )
        ( struct button_s * , sfMouseMoveEvent *, sfRenderWindow *) ;
        enum e_gui_state state ;
        sfVector2f position ;
        sfVector2f size ;
        sfColor color ;
        sfFont *font ;
        sfText *text ;
        int button_index ;
    }button_t;

    typedef struct s_gui_options {
        struct button_s *option ;
        struct s_gui_options *next ;
    }t_gui_options;

    typedef struct s_gui_drop_menu {
        struct button_s *button ;
        struct s_gui_options *options ;
        int is_open ;
    }t_gui_drop_menu;

    typedef struct paint{
        sfRenderWindow *window;
        sfRenderWindow *newwindow;
        sfColor windowcolor;
        sfRectangleShape **overlay;
        sfRectangleShape *color_window_delim;
        sfSprite *pinceau;
        sfSprite *gomme;
        sfRenderTexture *rendertexture;
        sfTexture *pinceautexture;
        sfTexture *gommetexture;
        sfTexture *palettetexture;
        sfSprite *palette;
        sfCircleShape *palettecircle;
        sfEvent *event;
        int ctrl;
        char i;
        t_gui_drop_menu *drop_file_button;
        t_gui_drop_menu *drop_edit_button;
        t_gui_drop_menu *drop_help_button;
        draw_t *draw;
        vertex_list_t *vertexList;
        int is_drawing;
        sfColor color;
        sfImage *image;
        sfFont *font;
        float zoom;
        sfRectangleShape *chose_color_tab;
        t_gui_drop_menu *drop_open_button;
        int display_open_file;
        sfRectangleShape *recmousse;
        sfSprite *pipette;
        sfTexture *pipettetexture;
    } paint_t;

    #define POS(x, y) ((sfVector2f){x, y + drom_menu->button->size.y})

    void open_window(paint_t *paint);
    void analyse_events(paint_t *paint);
    button_t *init_button
    (sfVector2f position, sfVector2f size, sfColor color, char *text);
    sfBool is_hover
    (button_t *button, sfMouseMoveEvent *mouseMove, sfWindow *window);
    sfBool is_clicked(button_t *button, sfMouseButtonEvent *mouseButton);
    t_gui_drop_menu *add_option_drop_menu
    (t_gui_drop_menu *drop_menu, char *text, int index);
t_gui_drop_menu *create_drop_menu
        (sfVector2f position, sfVector2f size, sfColor color, char *text);
    void display_drop_menu(t_gui_drop_menu *drop_menu, sfRenderWindow *window);
    void analyse_event_button(paint_t *paint, t_gui_drop_menu *menu);
    void add_vertex_to_list(paint_t *paint);
    void init_vertex(sfVertexArray *vertex, sfVector2f pos, sfColor color);
    int app_main_loop(paint_t *paint);
    void init_window(paint_t *paint);
    sfRectangleShape *init_rect
    (paint_t *paint, sfVector2f pos, sfVector2f size, sfColor color);
    sfRectangleShape *init_rect_outline
    (paint_t *paint, sfVector2f pos, sfVector2f size, sfColor color);
    void file_drop_button(paint_t *paint);
    void init_sprite_pinceau(paint_t *paint);
    void init_sprite_gomme(paint_t *paint);
    void init_sprite_palette(paint_t *paint);
    void display_drop_down_button(paint_t *paint, t_gui_drop_menu *menu);

    void init_vectrice(paint_t *paint);
    void create_point(paint_t *paint, draw_t *draw);
    void init_draw(paint_t *paint);

    void display_pencil(paint_t *paint);
    void display_window(paint_t *paint);

    void save_function(paint_t *paint);

    int my_strlen(char *str);
    char *str_concat_with_number(char *str1, char c);
    char *str_concat(char *str1, char *str2);

    void get_save_file(paint_t *paint);
    void init_drop_down_button(paint_t *paint);
    void display_save_file(paint_t *paint);

    void help_function(paint_t *paint);
    int main(void);
    void new_function(paint_t *paint);

    void add_new_vertex_to_list(paint_t *paint);
    void redo_function(paint_t *paint);
    void undo_function(paint_t *paint);
    int is_in_circle(sfMouseButtonEvent *pos, sfCircleShape *circle);
    void event_on_open_button_event(paint_t *paint);
    void analyse_file_open_hover(paint_t *paint, t_gui_drop_menu *menu);
    void rec_color(paint_t *paint);
    void pipette(paint_t *paint);
    void init_sprite_pipette(paint_t *paint);
#endif /* !PAINT_H_ */
