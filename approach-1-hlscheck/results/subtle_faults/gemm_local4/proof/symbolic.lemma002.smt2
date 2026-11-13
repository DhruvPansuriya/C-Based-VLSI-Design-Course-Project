; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x381826 (bvmul arg0_1 arg1_6)))
(let ((?x379309 (bvmul (_ bv4294967295 32) ?x381826)))
(let ((?x372369 (bvmul arg0_1 arg1_7)))
(let ((?x409097 (bvadd ?x372369 ?x379309)))
(and (distinct ?x409097 (_ bv0 32)) true))))))
(check-sat)
