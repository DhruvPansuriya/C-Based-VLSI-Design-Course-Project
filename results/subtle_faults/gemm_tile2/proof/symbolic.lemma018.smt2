; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x11306 (bvmul arg0_11 arg1_12)))
(let ((?x487761 (bvmul (_ bv4294967295 32) ?x11306)))
(let ((?x503864 (bvmul arg0_11 arg1_13)))
(let ((?x472495 (bvadd ?x503864 ?x487761)))
(and (distinct ?x472495 (_ bv0 32)) true))))))
(check-sat)
