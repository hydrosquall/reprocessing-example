open Reprocessing;

type stateT = {
  angle: float
};

let setup = (env) : stateT => {
  Env.size(~width=400, ~height=400, env);
  {
    angle: 0.
  };
};

/* Define Colors Once */
let bgColor = Utils.color(~r=0, ~g=0, ~b=0, ~a=255);
let fgColor = Utils.color(~r=255,~g=255,~b=255, ~a=255);

let draw = (_state: stateT, env): stateT => {

  let { angle } = _state;

  Draw.background(bgColor, env);
  Draw.fill(fgColor, env);
  Draw.rectMode(Center, env);

  let oscillatingValue = int_of_float(sin(angle) *. 100.);
  let height = Utils.remap(~value=oscillatingValue,
                          ~low1=-100, ~high1=100,
                          ~low2=10, ~high2=200);

  let xPos = Env.width(env) / 2;
  let yPos = Env.height(env) / 2;
  let rectangleCenter = (xPos, yPos);

  Draw.rect(~pos=rectangleCenter,
            ~width=10,
            ~height=height, env);

  {
    angle: (angle +. 0.07)
  };
};

run(~setup, ~draw, ());
