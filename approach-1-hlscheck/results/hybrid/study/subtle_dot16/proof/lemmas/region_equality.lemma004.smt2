; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x316624 (bvmul arg0_6 arg1_7)))
(let ((?x578336 (bvmul (_ bv4294967295 32) ?x316624)))
(let ((?x489108 (bvmul arg0_7 arg1_7)))
(let ((?x350262 (bvadd ?x489108 ?x578336)))
(and (distinct ?x350262 (_ bv0 32)) true))))))
(check-sat)
