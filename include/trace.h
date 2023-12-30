/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:02:13 by yusekim           #+#    #+#             */
/*   Updated: 2023/12/27 11:59:04 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

t_ray		ray(t_point3 orig, t_vec3 dir);
t_point3	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_color3	ray_color(t_scene *scene);
void		set_face_normal(t_ray *r, t_hit_rec *rec);
t_bool		hit(t_object *obj, t_ray *ray, t_hit_rec *rec);
t_bool		hit_obj(t_object *obj, t_ray *ray, t_hit_rec *rec);
t_color3	phong_lighting(t_scene *scene);
t_color3	point_light_get(t_scene *scene, t_light *light);
t_bool		in_shadow(t_scene *scene, t_light *light, t_vec3 *light_dir);

t_bool		hit_cy(t_cylinder *cy, t_ray *ray, t_hit_rec *rec, t_color3 albedo);
t_bool		hit_pl(t_plane *pl, t_ray *ray, t_hit_rec *rec, t_color3 albedo);
t_bool		hit_disk(t_disk *dk, t_ray *ray, t_hit_rec *rec, t_color3 albedo);
t_bool		hit_sp(t_sphere *sp, t_ray *ray, t_hit_rec *rec, t_color3 albedo);
t_bool	hit_cone(t_cone *cn, t_ray *ray, t_hit_rec *rec, t_color3 albedo);
t_bool		hit_cb(t_cb *cb, t_ray *ray, t_hit_rec *rec, t_color3 albedo);

#endif
