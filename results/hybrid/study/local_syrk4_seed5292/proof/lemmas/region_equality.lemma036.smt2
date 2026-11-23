; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x463959 (bvmul arg0_7 arg0_9)))
(let ((?x361299 (bvmul (_ bv4294967295 32) ?x463959)))
(let ((?x488547 (bvmul arg0_13 arg0_9)))
(let ((?x432539 (bvadd ?x488547 ?x361299)))
(and (distinct ?x432539 (_ bv0 32)) true))))))
(check-sat)
