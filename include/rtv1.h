/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:13:44 by gordey            #+#    #+#             */
/*   Updated: 2020/11/11 15:24:52 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "mlx.h"
# include "libft.h"
# include <OpenCL/cl.h>
# include <stdio.h>

# define WIN_WID 1000
# define WIN_HIG 750
# define WIN_DIST 750
# define FOV 66

# define ESC 53

# define T_MIN 0.0

# define DEFAULT_COORDINATE 0.0
# define DEFAULT_R 1.0
# define DEFAULT_A 2.0
# define DEFAULT_CAMERA 0.0
# define DEFAULT_LIGHT 0.0
# define DEFAULT_INTENSIVITY 0.3
# define DEFAULT_SPECULAR -1.0
# define DEFAULT_COLOR (t_color){255, 255, 255}

# define RED (t_color){255, 0, 0}
# define ORANGE (t_color){255, 150, 0}
# define YELLOW (t_color){255, 255, 0}
# define GREEN (t_color){0, 255, 0}
# define BLUE (t_color){0, 0, 255}
# define PINK (t_color){255, 0, 255}
# define METAL (t_color){150, 150, 150}
# define WHITE (t_color){255, 255, 255}

enum				e_lighttypes
{
	AMBIENT,
	POINT,
	DIRECTIONAL
};

enum				e_objecttype
{
	SPH,
	CYLINDER,
	CONE,
	PLANE
};

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img_ptr;
	int				*img_data;
	int				bit_pp;
	int				endian;
	int				size_line;
}					t_mlx;

typedef struct		s_quadr_equation
{
	double			a;
	double			b;
	double			c;
}					t_quadr_equation;

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_quat
{
	double			w;
	t_coord			vec;
}					t_quat;

typedef struct		s_sph
{
	t_coord			center;
	t_color			color;
	double			rad;
	double			specular;
}					t_sph;

typedef struct		s_cylindr
{
	t_coord			center;
	t_color			color;
	t_coord			direction;
	double			rad;
	double			specular;
}					t_cylindr;

typedef struct		s_cone
{
	t_coord			center;
	t_color			color;
	t_coord			direction;
	double			angle;
	double			specular;
}					t_cone;

typedef struct		s_plane
{
	t_coord			center;
	t_color			color;
	t_coord			direction;
	double			specular;
}					t_plane;

typedef struct		s_light
{
	int				type;
	double			intensity;
	t_coord			pos_or_dir;
	t_color			color;
}					t_light;

typedef struct		s_vector
{
	t_coord			point;
	t_coord			direct;
	t_coord			angles;
	t_quat			roter;
}					t_vector;

typedef struct		s_scene
{
	t_vector		camera;

	t_color			pix_color;

	t_sph			*sph_objs;
	int				num_sphs;

	t_cylindr		*cyln_objs;
	int				num_cylns;

	t_cone			*cone_objs;
	int				num_cons;

	t_plane			*plane_objs;
	int				num_plans;

	t_light			*light_srcs;
	int				num_l_src;
}					t_scene;

typedef struct		s_objectinfo
{
	int				type;
	int				index;
	t_coord			point;
	t_coord			center;
	t_coord			st_cent;
	t_coord			normal;
	t_color			color_obj;
	double			t;
	double			specular;
}					t_objectinfo;

typedef struct		s_raydata
{
	double			t_max;
	double			t_near;
	t_coord			direction;
	t_coord			cent_obj;
	t_coord			st_cent;
	t_coord			point;
}					t_raydata;

typedef struct		s_data
{
	t_mlx			*mlx;
	t_scene			*p_object;
}					t_data;

int					assignment(t_data *data, char *param_name);
void				file_extension(char *param_name);
void				oneline(t_data *data, t_scene *objects, char *line);
void				read_scene(t_data *data, char *name);
void				all_free(t_data *data);
int					exit_error(char *text);
void				exit_free(char *text, int code, t_data *data);
void				grafic(t_data *data, t_mlx *mlx);
void				mlxinit(t_mlx *mlx);
int					close_window(t_data *data);
void				struct_preset(t_scene *object);
int					buttons_press(int key, t_data *data);
void				checkcamlight(int *flags);
void				draw(int **img_data, t_scene object);
void				sphere(t_data *data, t_scene *object, char **arr);
void				cylinder(t_data *data, t_scene *object, char **arr);
void				cone(t_data *data, t_scene *object, char **arr);
void				plane(t_data *data, t_scene *object, char **arr);
void				camera(t_scene *object, char **arr);
void				light(t_data *data, t_scene *object, char **arr);
void				position(t_coord *p, char *arr, t_data *p_data);
void				color(t_color *color, char *arr);
void				ft_safe_free_arr(char **arr);
double				coordinate(char *str);
double				min(double a, double b);

void				set_default(t_scene *objs);
void				object_null(t_scene *objs);

t_color				get_color(t_scene objs, int type, int index);
int					get_specul(t_scene objs, int type, int index);
t_coord				get_direction(t_vector camera, int x, int y);

t_color				trace_to_light_src(t_objectinfo near, t_scene objs);

double				quadr_equation(t_quadr_equation factor, t_raydata *ray);
t_coord				vect_normal(t_coord vector);
double				vect_len(t_coord q);
t_coord				vec_rotation(t_coord vector, t_quat roter);

t_quat				quat_roter(t_vector camera);
t_quat				quat_mol(t_quat a, t_quat b);
void				quat_normal(t_quat *q);

int					ray_trace(t_scene objs, t_raydata ray, t_objectinfo *near);

t_color				colors_sum(t_color v1, t_color v2);
t_color				color_scal(t_color color, double mult);
void				color_change(t_color *color, t_color rgb);
t_color				colors_mult(t_color v1, t_color v2);

double				dot(t_coord v_1, t_coord v_2);
t_coord				vect_sum(t_coord vec_1, t_coord vec_2);
t_coord				vect_mult(t_coord vector, double mult);
t_coord				vect_sub(t_coord begin_point, t_coord end_point);
t_coord				vect_reverse(t_coord vector);

int					fixing_the_near_obj(t_raydata ray, t_objectinfo *near,
										int type, int index);
t_raydata			creat_ray(double max_len, t_coord point,
													t_coord direction);

t_coord				object_normal(t_scene objs, t_objectinfo near);
t_coord				cone_normal(t_coord rotation, t_objectinfo near,
										float angle, t_coord direct);
t_coord				cylin_normal(t_coord rotation, t_objectinfo near,
										t_coord direct);
t_coord				plane_normal(t_coord plane_direct, t_coord cam_direct);

void				put_color_to_img(int **img_data, int x, int y,
									t_color color);

#endif
