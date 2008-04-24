/*  $Id$
**   __      __ __             ___        __   __ __   __
**  /  \    /  \__| ____    __| _/_______/  |_|__|  | |  |   ____
**  \   \/\/   /  |/    \  / __ |/  ___/\   __\  |  | |  | _/ __ \
**   \        /|  |   |  \/ /_/ |\___ \  |  | |  |  |_|  |_\  ___/
**    \__/\  / |__|___|  /\____ /____  > |__| |__|____/____/\___  >
**         \/          \/      \/    \/                         \/
**  Copyright (C) 2007 Ingo Ruhnke <grumbel@gmx.de>
**
**  This program is free software; you can redistribute it and/or
**  modify it under the terms of the GNU General Public License
**  as published by the Free Software Foundation; either version 2
**  of the License, or (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
** 
**  You should have received a copy of the GNU General Public License
**  along with this program; if not, write to the Free Software
**  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
**  02111-1307, USA.
*/

#include "control.hpp"

void
BtnPortOut::connect(BtnPortIn* in)
{
  if (in)
    {
      in->out_port = this;
      sig_change.connect(in->on_change);
    }
}

void
BtnPortOut::connect(boost::function<void(BtnPortOut*)> func)
{
  sig_change.connect(func);
}

BtnPortIn*
Control::get_btn_port_in(int idx)
{
  if (idx >= 0 && idx < (int)btn_port_in.size())
    return btn_port_in[idx];
  else
    return 0;
}

BtnPortOut*
Control::get_btn_port_out(int idx) 
{
  if (idx >= 0 && idx < (int)btn_port_out.size())
    return btn_port_out[idx]; 
  else
    return 0;
}

void
AbsPortOut::connect(AbsPortIn* in)
{
  if (in)
    {
      in->out_port = this;
      sig_change.connect(in->on_change);
    }
}

void
AbsPortOut::connect(boost::function<void(AbsPortOut*)> func)
{
  sig_change.connect(func);
}

AbsPortIn*
Control::get_abs_port_in(int idx) 
{
  if (idx >= 0 && idx < (int)abs_port_in.size())
    return abs_port_in[idx];  
  else 
    {
      LOG("Couldn't find abs-in port " << idx);
      return 0;
    }
}

AbsPortOut*
Control::get_abs_port_out(int idx) 
{
  if (idx >= 0 && idx < (int)abs_port_out.size())
    return abs_port_out[idx]; 
  else
    {
      LOG("Couldn't find abs-out port " << idx);
      return 0;
    }
}

/* EOF */