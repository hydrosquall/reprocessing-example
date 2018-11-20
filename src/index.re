open Reprocessing;

type stateT = {
  angle: float,
}

let setup = (env) => {
  Env.size(~width=600,
            ~height=600,
            env);

  {
    angle: 0.,
  }
}

let backgroundColor = Utils.color(~r=0, ~g=0, ~b=0, ~a=255);
let foregroundColor = Utils.color(~r=255, ~g=255, ~b=255, ~a=255);

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
  let { angle } = _state;

  let oscillator = sin(angle);
  let height = int_of_float(Utils.remapf(~value=oscillator,
                                          ~low1=-1.,
                                          ~high1=1.,
                                          ~low2=10.,
                                          ~high2=200.));
  Draw.rect(~pos=(0, 0),
            ~width=20,
            ~height,
            env);

  {..._state, angle: angle +. 0.1}
};

run(~setup, ~draw, ());
