open Reprocessing;

let setup = (env) => Env.size(~width=600,
                              ~height=600,
                              env);

let backgroundColor = Utils.color(~r=0, ~g=0, ~b=0, ~a=255);
let foregroundColor = Utils.color(~r=41, ~g=166, ~b=244, ~a=255); /* Blueish */

let draw = (_state, env) => {
  /* Drawing Setup */
  Draw.background(backgroundColor, env);
  Draw.fill(foregroundColor, env);
  Draw.rectMode(Center, env);

  /* Draw from center of page */
  let midpointX = float_of_int(env.size.width) /. 2.;
  let midpointY = float_of_int(env.size.height) /. 2.;

  Draw.translate(~x=midpointX,
                 ~y=midpointY,
                 env);

  Draw.rect(~pos=(0, 0),
            ~width=300,
            ~height=300,
            env);
};

run(~setup, ~draw, ());
